#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>    // for sockaddr_in
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <sys/select.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char** argv) {
    printf("hello world\n");
    int sk = socket(AF_INET, SOCK_STREAM, 0);
    printf("socket ret=%d\n", sk);
    uint16_t port = 7777;
    if (argc >= 2) {
        port = atoi(argv[1]);
    }
    //设置为非阻塞accept
//    fcntl(sk,F_SETFL,O_NONBLOCK);

    /* 
     sockaddr_in 是IP sockaddr 通用的 
     q1:地址如何转换？
     */
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    int ret = bind(sk, (struct sockaddr *) &addr, sizeof (addr));
    if (ret < 0) {
        printf("bind err port=%d,ret=%d\n", port, ret);
        return 0;
    }
    ret = listen(sk, 30000);
    printf("listen port=%d, ret=%d\n", port, ret);
    /*-------------------测试文件描述符与网络fd -------------------*/
    int pfd;
    if ((pfd = open("./Makefile", O_WRONLY )) == -1){
        printf("open file err port=%d,ret=%d\n", port, ret);
        return 0;
    }
    printf("open file fd=%d\n", pfd);
    /*-----------------------------------------------------*/
    //client 地址
    struct sockaddr_in caddr;
    socklen_t length = sizeof (caddr);
    fd_set rfds;
    int c_fd,max = sk;
    struct timeval tv;
    tv.tv_sec = 50000;
    tv.tv_usec = 0;
    char buff[500];
    int arr[100];
    while (1) {
//        continue;
//        sleep(10);
        FD_ZERO(&rfds);
        for (int i = 3; i <= max; i++) {
            if(arr[i] == -1) continue;
            //要剔除掉已经close的
//            printf("set fd=%d\n", i);
            FD_SET(i, &rfds);
        }

        //int select(int nfds, fd_set *readfds, fd_set *writefds,fd_set *exceptfds, struct timeval *timeout);
        int ret = select(max + 1, &rfds, NULL, NULL, &tv);
        printf("select ret=%d,max=%d\n", ret, max);
        if (ret <= 0) {
            continue;
        }
        if (FD_ISSET(sk, &rfds)) {
            c_fd = accept(sk, (struct sockaddr *) &caddr, &length);
            //如果中间有一个fd close了，后面的新连接会重新使用原来的fd值，所以后面接收到的client的fd不一定比前面的大。
            if (c_fd > max) max = c_fd;
            arr[c_fd] = c_fd;
            printf("FD_ISSET client fd=%d,errno=%d,port=%d \n", c_fd,errno, ntohs(caddr.sin_port));
        } else {
            //一直打印是因为业务层没有接受数据导致一直有事件触发
            for (int i = 0; i <= max; i++) {
                /* !!!!!! 循环用i，不然recv/write不到 !!!!! */
                if (FD_ISSET(i, &rfds)) {
                    int len = recv(i, buff, 500, 0);
                    if (len <= 0) {
                        close(i);
                        //下次循环不加入到fds中
                        arr[i] =-1;
                        printf("close fd=%d\n", i);
                        break;
                    }
                    printf("recv len=%d,buff=%s", len, buff);
                    write(i, buff, len);
                }
            }
        }
    }
}
