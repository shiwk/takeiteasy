//
// Created by swk on 2019-06-23.
//

#ifndef CPP_LTC_ARRAYQUEUE_H
#define CPP_LTC_ARRAYQUEUE_H

namespace happycoding {
    template <typename T>
    class arrayqueue {

    public:
        explicit arrayqueue(int n);

        bool enqueue(T *t);

        T *dequeue();

        int count();

    private:
        int head;
        int tail;
        int size;
        T *arr;
    };
}

#endif //CPP_LTC_ARRAYQUEUE_H
