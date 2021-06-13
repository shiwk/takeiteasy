//
// Created by shiwk on 2021/4/11.
//

#ifndef CPP_CLI_HPP
#define CPP_CLI_HPP
#include <mutex>

static std::mutex mutex;

struct CLIENT {
public:
    char *name;
    struct sockaddr_in addr;
    char *data;

    void process_cli(char *recvbuf, size_t recvlen, char *sendbuf, int &sendlen) {
        std::unique_lock<std::mutex> lock(mutex);
        int j;
        recvbuf[recvlen - 1] = '\0';
        std::cout<< "tid["<< std::this_thread::get_id() << "] : ";
        if (strlen(name) == 0) {
            memcpy(name, recvbuf, recvlen);
            printf("Client's name is %s.\n", name);
            return;
        }

        printf("Received client( %s ) message: %s\n", name, recvbuf);
        savedata(recvbuf, recvlen);
        for (j = 0; j < recvlen - 1; j++) {
            sendbuf[j] = recvbuf[recvlen - j - 2];
        }
        sendbuf[recvlen - 1] = '\0';
        sendlen = strlen(sendbuf);
    }

private:
    void savedata(char *recvbuf, size_t len) {
        int i;
        int start = strlen(data);
        for (i = 0; i < len; i++) {
            data[start + i] = recvbuf[i];
        }
    }
};


#endif //CPP_CLI_HPP
