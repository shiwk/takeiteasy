//
// Created by shiwk on 2021/4/9.
//

#include <cstdio>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <future>
#include <poll.h>
#include <unordered_map>
#include <thread_pool.hpp>
#include <cli.hpp>

#define PORT 1234
#define BACKLOG 5
#define MAXDATASIZE 1000


[[noreturn]] void main_loop(int);

int main() {
    int sockfd;
    struct sockaddr_in server;

    // SOCK_STREAM means tcp sockert
    //  SOCK_DGRAM means that it is a UDP socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        perror("Creating socket failed.");
        exit(1);
    }

    int opt = SO_REUSEADDR;

//    The level argument specifies the protocol level at which the option resides.
//    To set options at the socket level, specify the level argument as SOL_SOCKET.
//    To set options at other levels, supply the appropriate level identifier for the protocol controlling the option.
//    For example, to indicate that an option is interpreted by the TCP (Transport Control Protocol), set level to IPPROTO_TCP
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(sockfd, (struct sockaddr *) &server, sizeof(struct sockaddr)) == -1) {
        perror("Bind error.");
        exit(1);
    }

    std::cout << "Server bind to " << inet_ntoa(server.sin_addr) << ":" << ntohs(server.sin_port) << std::endl;

    //listen() marks the socket referred to by sockfd as a passive
    //socket, that is, as a socket that will be used to accept incoming
    //connection requests using accept(2).
    if (listen(sockfd, BACKLOG) == -1) {
        perror("listen() error\n");
        exit(1);
    }

//    main_loop(sockfd);
    std::future<void> loop = std::async(std::launch::async, main_loop, sockfd);
    loop.wait();
    std::cout << "Server shutdown" << std::endl;
    shutdown(sockfd, SHUT_WR);
    close(sockfd);
}

[[noreturn]] void main_loop(int serverSockfd) {
    std::unordered_map<int, struct CLIENT> clients(FD_SETSIZE);
    uint32_t sin_size = sizeof(struct sockaddr_in);
    int maxi = -1;
    int i;
    pollfd pollfds[FD_SETSIZE];
    for (i = 0; i < FD_SETSIZE; i++) {
        pollfds[i].fd = -1;
    }

    pollfds[0].fd = serverSockfd;
    pollfds[0].events = POLLIN;
    ThreadPool thread_poll(10);
    thread_poll.init();

    int nready;
    while (true) {
        nready = poll(pollfds, FD_SETSIZE, -1);

        if (pollfds[0].revents & POLLIN) {
            // accept new connection
            struct sockaddr_in addr;
            int connectfd;
            if ((connectfd = accept(serverSockfd, (struct sockaddr *) &addr, &sin_size)) == -1) {
                perror("accept() error\n");
                continue;
            }
            for (i = 0; i < FD_SETSIZE; i++)
                if (pollfds[i].fd < 0) {
                    pollfds[i].fd = connectfd;
                    pollfds[i].events = POLLIN;

                    struct CLIENT client{};
//                    clients[i].fd.events = POLLIN;
                    client.name = static_cast<char *>(malloc(sizeof(char[MAXDATASIZE])));
                    client.addr = addr;
                    client.data = static_cast<char *>(malloc(sizeof(char[MAXDATASIZE])));
                    client.name[0] = '\0';
                    client.data[0] = '\0';

                    clients[connectfd] = client;
                    std::cout<< "tid["<< std::this_thread::get_id() << "] : ";
                    std::cout << "You got a connection from " << inet_ntoa(client.addr.sin_addr) << ":"
                              << ntohs(client.addr.sin_port) << std::endl;
                    break;
                }
            if (i == FD_SETSIZE) printf("too many clients\n");
            if (i > maxi) maxi = i;
            if (--nready <= 0) continue;
        }

        auto callback = [](int fd, CLIENT *client, char *recvbuf, int recvLen) {
            int sendlen = 0;
            char sendbuf[MAXDATASIZE];
            client->process_cli(recvbuf, recvLen, sendbuf, sendlen);
            send(fd, sendbuf, sendlen, 0);
        };

        for (i = 1; i <= maxi; i++) {
            if (pollfds[i].fd < 0) continue;
            if (pollfds[i].revents & POLLIN) {
                ssize_t n;
                char* recvbuf = new char [MAXDATASIZE];
                if ((n = recv(pollfds[i].fd, recvbuf, MAXDATASIZE, 0)) == 0) {
                    close(pollfds[i].fd);
                    struct CLIENT client = clients[pollfds[i].fd];
                    printf("Client( %s ) closed connection. User's data: %s\n", client.name, client.data);

                    delete client.name;
                    delete client.data;
                    clients.erase(pollfds[i].fd);
                    pollfds[i].fd = -1;
                } else {
                    thread_poll.submit(callback, pollfds[i].fd, &clients[pollfds[i].fd], recvbuf, n);
                }

                pollfds[i].revents = 0;// reset;
                if (--nready <= 0) break;
            }
        }
    }

    thread_poll.shutdown();
}