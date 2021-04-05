//
// Created by shiwk on 2021/3/16.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include <arpa/inet.h>
#include <poll.h>

#define MAXBUF 256
#define CLIENTCOUNT 1

void child_process(void) {
    int t = (random() % 10) + 1;
    sleep(t);
    char msg[MAXBUF];
    struct sockaddr_in addr = {0};
    int n, sockfd, num = 1;
    srandom(getpid());
    /* Create socket and connect to server */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(2000);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));

    printf("child {%d} connected \n", getpid());
    while (1) {
        int sl = (random() % 10) + 1;
        num++;
        sleep(sl);
        sprintf(msg, "Test message %d from client %d", num, getpid());
        n = write(sockfd, msg, strlen(msg));    /* Send message */
    }

}

void select_event(int sockfd, sockaddr_in &client) {
    fd_set rset;
    int fds[5];
    int addrlen, n, i, max = 0;;

    for (i = 0; i < 5; i++) {
        memset(&client, 0, sizeof(client));
        addrlen = sizeof(client);
            fds[i] = accept(sockfd, (struct sockaddr *) &client, reinterpret_cast<socklen_t *>(&addrlen));
        printf("fd created.\n");
        if (fds[i] > max)
            max = fds[i];
    }
    char buffer[MAXBUF];

    while (1) {
        FD_ZERO(&rset);
//        printf("size of rset.fds_bits is %lu\n", sizeof(rset.fds_bits));

        for (int i = 0; i < 5; i++) {
            FD_SET(fds[i], &rset);
        }

        puts("round again");
//        printf("before select size of rset.fds_bits is %lu\n", sizeof(rset.fds_bits));
        select(max + 1, &rset, NULL, NULL, NULL);
//        printf("after select  size of rset.fds_bits is %lu\n", sizeof(rset.fds_bits));

        for (i = 0; i < 5; i++) {
            if (FD_ISSET(fds[i], &rset)) {
                printf("fd %d event.", i);
                memset(buffer, 0, MAXBUF);
                read(fds[i], buffer, MAXBUF);
                puts(buffer);
            }
        }
    }
}


void poll_event(int sockfd, sockaddr_in &client) {
    pollfd pollfds[5];
    int addrlen, i = 0;

    for (i = 0; i < CLIENTCOUNT; i++) {
        memset(&client, 0, sizeof(client));
        addrlen = sizeof(client);
        pollfds[i].fd = accept(sockfd, (struct sockaddr *) &client, reinterpret_cast<socklen_t *>(&addrlen));
        pollfds[i].events = POLLIN;
        printf("fd created.\n");
    }
    char buffer[MAXBUF];

    sleep(1);
    while (1) {
        puts("round again");
        poll(pollfds, CLIENTCOUNT, 50000);

        for (i = 0; i < CLIENTCOUNT; i++) {
            if (pollfds[i].revents & POLLIN) {
                printf("fd %d event.", i);

                pollfds[i].revents = 0;
                memset(buffer, 0, MAXBUF);
                read(pollfds[i].fd, buffer, MAXBUF);
                puts(buffer);
            }
        }
    }
}

//void epoll_events(int sockfd, sockaddr_in &client){
//    int addrlen, i=0;
//
//    struct epoll_event events[5];
//    int epfd = epoll_create(10);
//    for (i=0;i<5;i++)
//    {
//        static  struct epoll_event ev;
//        memset(&client, 0, sizeof (client));
//        addrlen = sizeof(client);
//        ev.data.fd = accept(sockfd,(struct sockaddr*)&client, &addrlen);
//        ev.events = EPOLLIN;
//        epoll_ctl(epfd, EPOLL_CTL_ADD, ev.data.fd, &ev);
//    }
//
//    while(1){
//        puts("round again");
//        nfds = epoll_wait(epfd, events, 5, 10000);
//
//        for(i=0;i<nfds;i++) {
//            memset(buffer,0,MAXBUF);
//            read(events[i].data.fd, buffer, MAXBUF);
//            puts(buffer);
//        }
//    }
//}
static void sig_child(int signo);


//int main() {
//
//    struct sockaddr_in addr;
//    struct sockaddr_in client;
//    int sockfd, commfd;
////    signal(SIGCHLD, sig_child);
//    for (int i = 0; i < CLIENTCOUNT; i++) {
//        if (fork() == 0) {
//            child_process();
//            exit(0);
//        }
//    }
//
//    sockfd = socket(AF_INET, SOCK_STREAM, 0);
//    memset(&addr, 0, sizeof(addr));
//    addr.sin_family = AF_INET;
//    addr.sin_port = htons(2000);
//    addr.sin_addr.s_addr = INADDR_ANY;
//    bind(sockfd, (struct sockaddr *) &addr, sizeof(addr));
//    listen(sockfd, CLIENTCOUNT);
//
//    poll_event(sockfd, client);
//
//}


static void sig_child(int signo) {
    pid_t pid;
    int stat;
    //zombie process
    while ((pid = waitpid(-1, &stat, WNOHANG)) > 0)
        printf("child   %d terminated.\n", pid);
}