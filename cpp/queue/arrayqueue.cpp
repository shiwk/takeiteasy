//
// Created by swk on 2019-06-23.
//

#include "arrayqueue.h"

namespace happycoding{
    template <typename T>
    bool arrayqueue<T> :: enqueue(T* t) {
        if (t == nullptr)
            return false;
        if(tail == size && head == 0)
            return false;

        if(tail == size)
        {
            // need move head to 0
            for (int i = head; i < size; ++i) {
                arr[i - head] = arr[i];
            }
            head = 0;
            tail = size - head;
        }

        arr[tail] = *t;
        tail++;
        return true;
    }

    template <typename T>
    T* arrayqueue<T> ::dequeue() {
        if(tail == head)
            return nullptr;
        int* res = arr + head++;
        if(tail == head && head == size)
        {
            head = 0, tail = 0;
        }

        return res;
    }

    template <typename T>
    arrayqueue<T> ::arrayqueue(const int n) {
        tail = 0;
        head = 0;
        size = n;
        arr = new T[n];
    }

    template <typename T>
    int arrayqueue<T> ::count() {
        return tail - head;
    }
}
