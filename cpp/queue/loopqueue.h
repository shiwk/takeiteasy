//
// Created by swk on 2019-06-25.
//

#ifndef CPP_LTC_LOOPQUEUE_H
#define CPP_LTC_LOOPQUEUE_H

namespace happycoding{
    class loopqueue {
    public:
        int dequeue();
        bool enqueue(int queue);
        explicit loopqueue(int size);
    private:
        int head;
        int tail;
        int size;
        int* arr;
    };
}



#endif //CPP_LTC_LOOPQUEUE_H
