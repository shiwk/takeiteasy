//
// Created by swk on 2019-03-24.
//

#ifndef CPP_LTC_MINHEAP_HPP
#define CPP_LTC_MINHEAP_HPP

#include <vector>
#include <string>

using namespace std;
namespace happycoding{
    static const string EmptyError ="Empty Heap";
    template <typename T>
    class Heap {
    public:
        explicit Heap(bool minRoot);
        T pop();
        void add(T value);
        unsigned long size();
        T top();
    private:
        T* nodes;
        bool isMinRoot;
        bool compare(const T& left, const T& right);
        unsigned int count;
        unsigned int capacity;
    };

    using ul = unsigned long;
    template <typename T>
    T Heap<T>::pop() {
        T res;
        if(count >= 1)
            res = nodes[0];
        else
            throw logic_error(EmptyError);

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
    void Heap<T>::add(T value) {
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
    unsigned long Heap<T>::size(){
        return count;
    }

    template<typename T>
    Heap<T>::Heap(bool minRoot) {
        isMinRoot = minRoot;
        count = 0;
        capacity = 8;
        nodes = new int[capacity];
    }

    template<typename T>
    bool Heap<T>::compare(const T& left, const T& right) {
        return left == right || !(left < right ^ isMinRoot) ;
    }

    template <typename T>
    T Heap<T>::top() {
        if(count <= 0)
            throw logic_error(EmptyError);
        return nodes[0];
    }
}


#endif //CPP_LTC_MINHEAP_HPP
