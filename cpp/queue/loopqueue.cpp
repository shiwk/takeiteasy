//
// Created by swk on 2019-06-25.
//

#include <stdexcept>
#include "loopqueue.h"

using namespace std;
happycoding::loopqueue::loopqueue(int size) {
    this->size = size;
    head = 0;
    tail = 0;
    arr = new int[size];
}

bool happycoding::loopqueue::enqueue(int num) {
    if(tail == head + size)
        return false;
    arr[tail++ % size] = num;
    return true;
}

int happycoding::loopqueue::dequeue() {
    if(tail == head)
    {
        throw logic_error("Empty queue");
    }

    return arr[head++ % size];
}