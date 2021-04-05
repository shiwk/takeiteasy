//
// Created by shiwk on 2021/4/5.
//

#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdlib>

#define PORT 1234
#define MAXDATASIZE 100

void process(FILE *fp, int sockfd);
char* getMessage(char* sendline,int len, FILE* fp);

int main(int argc, char *argv[])
{
    int fd;
    struct sockaddr_in server;
    if (argc !=2) {
        printf("Usage: %s <IP Address>\n",argv[0]);
        exit(1);
    }

    if ((fd=socket(AF_INET, SOCK_STREAM, 0))==-1){
        printf("socket() error\n");
        exit(1);
    }
    bzero(&server,sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(fd, (struct sockaddr *)&server,sizeof(struct sockaddr))==-1){
        printf("connect() error\n");
        exit(1);
    }
    process(stdin,fd);
    close(fd);
}
void process(FILE *fp, int sockfd)
{
    char sendline[MAXDATASIZE], recvline[MAXDATASIZE];
    int numbytes;
    printf("Connected to server. \n");

    printf("Input name : ");
    if ( fgets(sendline, MAXDATASIZE, fp) == NULL) {
        printf("\nExit.\n");
        return;
    }
    send(sockfd, sendline, strlen(sendline),0);

    while (getMessage(sendline, MAXDATASIZE, fp) != NULL) {
        send(sockfd, sendline, strlen(sendline),0);
        if ((numbytes = recv(sockfd, recvline, MAXDATASIZE,0)) == 0) {
            printf("Server terminated.\n");
            return;
        }
        recvline[numbytes]='\0';
        printf("Server Message: %s\n",recvline);
    }
    printf("\nExit.\n");
}
char* getMessage(char* sendline,int len, FILE* fp)
{
    printf("Input string to server:");
    return(fgets(sendline, MAXDATASIZE, fp));
}
