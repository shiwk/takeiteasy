//
// Created by swk on 2019-08-17.
//

#ifndef CPP_MEDIAN_HPP
#define CPP_MEDIAN_HPP

#include "heap.hpp"

namespace happycoding{
    template <typename T>
    class MedianFinder{
        public:
            MedianFinder():leftHeap(Heap<T>(false)), rightHeap(Heap<T>(true)), count(0){}
            void push(T t);
            T findMedian();
            unsigned int size();
        private:
            Heap<T> leftHeap;
            Heap<T> rightHeap;
            unsigned int count;
    };

    template <typename T>
    void MedianFinder<T>::push(T t) {
        if (count == 0 || t <= findMedian())
            leftHeap.add(t);
        else
            rightHeap.add(t);

        if (leftHeap.size() > rightHeap.size() + 1)
        {
            rightHeap.add(leftHeap.pop());
        }
        else if (rightHeap.size() > leftHeap.size())
        {
            leftHeap.add(rightHeap.pop());
        }
        count++;
    }

    template <typename T>
    T MedianFinder<T>::findMedian() {
        return leftHeap.top();
    }

    template <typename T>
    unsigned int MedianFinder<T>::size() {
        return count;
    }
}
#endif //CPP_MEDIAN_HPP
