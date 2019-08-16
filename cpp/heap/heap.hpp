//
// Created by swk on 2019-03-24.
//

#ifndef CPP_LTC_MINHEAP_HPP
#define CPP_LTC_MINHEAP_HPP

#include <vector>

using namespace std;
template <typename T>
class heap {
public:
    explicit heap(bool minRoot);
    T pop();
    void add(T value);
    unsigned long size();

private:
    T* nodes;
    bool isMinRoot;
    bool compare(const T& left, const T& right);
    int count;
    int capacity;
};

using ul = unsigned long;
using namespace std;

template <typename T>
T heap<T>::pop() {
    T res;
    if(count >= 1)
        res = nodes[0];
    else
        return T();

    swap(nodes[0], nodes[count - 1]);
    count--;

    unsigned long index = 0;
    while (true){
        ul child_index;
        ul leftChild =  2 * index + 1;
        ul rightChild = 2 * index + 2;
        if( rightChild < count)
        {
            child_index = compare(nodes[leftChild], nodes[rightChild]) ? leftChild : rightChild;
        }
        else if(leftChild < count)
        {
            child_index = leftChild;
        }
        else
        {
            break;
        }

        if(compare(nodes[child_index], nodes[index])){
            swap(nodes[index], nodes[child_index]);
            index = child_index;
        }
        else
            break;
    }
    return res;
}

template <typename T>
void heap<T>::add(T value) {
    if(count + 1 > capacity)
    {
        T * newNodes = new int[capacity * 2];
        for (int i = 0; i < capacity ; i++)
        {
            newNodes[i] = nodes[i];
        }
        delete []nodes;
        nodes = newNodes;
        capacity *= 2;
    }

    nodes[count++] = value;
    if (count == 1)
        return;
    ul index = count - 1;
    while (index > 0)
    {
        ul parent_index = (index -1) / 2;
        if(compare(nodes[parent_index], nodes[index]))
            break;
        else
        {
            swap(nodes[index], nodes[parent_index]);
            index = parent_index;
        }
    }
}

template <typename T>
unsigned long heap<T>::size(){
    return count;
}

template<typename T>
heap<T>::heap(bool minRoot) {
    isMinRoot = minRoot;
    count = 0;
    capacity = 8;
    nodes = new int[capacity];
}

template<typename T>
bool heap<T>::compare(const T& left, const T& right) {
    return left == right || !(left < right ^ isMinRoot) ;
}

#endif //CPP_LTC_MINHEAP_HPP
