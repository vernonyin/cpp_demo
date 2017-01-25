#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>    // for sockaddr_in
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <sys/select.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

int main(int argc, char** argv) {

    uint16_t port = 7777;
    if (argc >= 2) {
        port = atoi(argv[1]);
    }
    int count = 100;
    if (argc >= 3) {
        count = atoi(argv[2]);
    }
    int count1 = count;
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    //string to int
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr.s_addr);
    addr.sin_port = htons(port);

    char buff[100] = "hello world";
    int len = 50;
    printf("count=%d,addr=%d \n", count,addr.sin_addr.s_addr);
    // int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
    while (count--) {
        int sk = socket(AF_INET, SOCK_STREAM, 0);
        socklen_t length = sizeof (addr);
        int ret = connect(sk, (struct sockaddr *) &addr, length);
        if (ret < 0) {
            printf("connect err port=%d,ret=%d\n", port, ret);
            return 0;
        }
    }
    printf("count=%d \n", count);
    for (int i = 3; i < count1; i++) {
        int ret = write(i, buff, sizeof (buff));
        int ret2 = read(i, buff, len);
        printf("fd=%d,buff=%s,ret=%d,ret=%d \n", i, buff, ret, ret2);
    }
    printf("end..... \n");
    sleep(1000);
}
