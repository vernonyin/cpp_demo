#include <stdio.h>
#include <netinet/in.h>    // for sockaddr_in
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <sys/select.h>

int main(int argc, char** argv) {
    printf("hello world\n");
    int sk = socket(AF_INET, SOCK_STREAM, 0);
    printf("socket ret=%d\n", sk);
    uint16_t port = 7777;
    if (argc >= 2) {
        port = atoi(argv[1]);
    }

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


    ret = listen(sk, 1);
    printf("listen port=%d, ret=%d\n", port, ret);

    //client 地址
    struct sockaddr_in caddr;
    socklen_t length = sizeof (caddr);
    fd_set rfds;
    int c_fd;
    int max = sk;
    struct timeval tv;
    tv.tv_sec = 50000;
    tv.tv_usec = 0;
    char buff[500];
    //只要不clear就能保留
    while (1) {
        FD_ZERO(&rfds);
        for (int i = 0; i <= max; i++) {
            //要剔除掉已经close的
            printf("set fd=%d\n", i);
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
            max = c_fd;
            printf("FD_ISSET client fd=%d,port=%d\n", c_fd, ntohs(caddr.sin_port));
        } else {
            //一直打印是因为业务层没有接受数据导致一直有事件触发
            for (int i = sk; i <= max; i++) {
                /* !!!!!! 循环用i，不然recv/write不到 !!!!! */
                if (FD_ISSET(i, &rfds)) {
                    int len = recv(i, buff, 500, 0);
                    if (len <= 0) {
                        close(i);
                        printf("close fd=%d\n", c_fd);
                        break;
                    }
                    printf("recv len=%d,buff=%s", len, buff);
                    write(i, buff, len);
                }
            }
        }
    }
}
