#include <netinet/in.h>    // for sockaddr_in
#include <sys/types.h>    // for socket
#include <sys/socket.h>    // for socket
#include <unistd.h>
#include <stdio.h>        // for printf
#include <stdlib.h>        // for exit
#include <cstring>        // for bzero
/*
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
 */
#define HELLO_WORLD_SERVER_PORT    6666
#define LENGTH_OF_LISTEN_QUEUE 20
#define BUFFER_SIZE 1024
#define FILE_NAME_MAX_SIZE 512

int main(int argc, char **argv) {
    //设置一个socket地址结构server_addr,代表服务器internet地址, 端口
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof (server_addr)); //把一段内存区的内容全部设置为0
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(HELLO_WORLD_SERVER_PORT);

    //创建用于internet的流协议(TCP)socket,用server_socket代表服务器socket
    int sk = socket(PF_INET, SOCK_STREAM, 0);
    if (sk < 0) {
        printf("Create Socket Failed!");
        exit(1);
    }
    {
        int opt = 1;
        setsockopt(sk, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof (opt));
    }

    //把socket和socket地址结构联系起来
    if (bind(sk, (struct sockaddr*) &server_addr, sizeof (server_addr))) {
        printf("Server Bind Port : %d Failed!", HELLO_WORLD_SERVER_PORT);
        exit(1);
    }

    //server_socket用于监听
    if (listen(sk, LENGTH_OF_LISTEN_QUEUE)) {
        printf("Server Listen Failed!");
        exit(1);
    }
 //定义客户端的socket地址结构client_addr
    struct sockaddr_in client_addr;
    socklen_t length = sizeof (client_addr);

    int fd = accept(sk, (struct sockaddr*) &client_addr, &length);
    if (fd < 0) {
        printf("Server Accept Failed!\n");
        return 0;
    }
    fd_set rfds;
    while (1) //服务器端要一直运行
    {
       
        printf(" Accepted fd=%d!\n",fd);
        FD_ZERO(&rfds);
        FD_SET(fd, &rfds); //这里set fd 0

        struct timeval tv;
        tv.tv_sec = 100;
        tv.tv_usec = 0;

        int retval = select(1000, &rfds, NULL, NULL, &tv);
        /* Don't rely on the value of tv now! */
        if (retval == -1)
            perror("select()");
        else if (retval) {
            if (FD_ISSET(fd, &rfds)) {
                char buffer[BUFFER_SIZE];
                bzero(buffer, BUFFER_SIZE);
                int leng = recv(fd, buffer, BUFFER_SIZE, 0);
                printf("Data is set length=%d,buffer=%s",leng,buffer);
                if (length < 0) {
                    printf("Server Recieve Data Failed!\n");
                    return 0;
                }
            }
        } else
            printf("No data within five seconds.\n");
    }
    //关闭监听用的socket
    close(sk);
    return 0;
}
