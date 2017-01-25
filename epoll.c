#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>    // for sockaddr_in
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>

#define MAX_EVENTS 100

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
    ret = listen(sk, 30000);
    /*-----------------------------------------------------*/
    struct epoll_event ev, events[MAX_EVENTS];
    /*
      In the initial epoll_create() implementation, the size argument informed the kernel of
       the  number of file descriptors that the caller expected to add to the epoll instance.
       The kernel used this information as a hint for the amount of space to initially  allo‐
       cate  in  internal data structures describing events.  (If necessary, the kernel would
       allocate more space if the caller's usage exceeded the hint given in size.)  Nowadays,
       this hint is no longer required (the kernel dynamically sizes the required data struc‐
       tures without needing the hint), but size must still be greater than zero, in order to
       ensure backward compatibility when new epoll applications are run on older kernels.
*/
    int epollfd = epoll_create(1024); /* 1024 is just a hint for the kernel */
    ev.events = EPOLLIN;
    ev.data.fd = sk;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, sk, &ev) == -1) {
        printf("epoll_ctl: listen_sock");
        exit(0);
    }
    struct sockaddr_in caddr;
    int length;
    while (1) {
        int nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (nfds <= 0) {
            printf("epoll_wait fail nfds=%d\n", nfds);
            return 0;
        }
        printf("epoll_wait nfds=%d\n", nfds);
        for (int i = 0; i < nfds; i++) {
            if (events[i].data.fd == sk) {
                int c_fd = accept(sk, (struct sockaddr *) &caddr, &length);
                printf("accpet succ fd=%d\n", c_fd);
                close(c_fd);
            }
        }

    }
}
