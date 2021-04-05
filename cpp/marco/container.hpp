//
// Created by shiwk on 2021/2/25.
//

#ifndef CPP_STACK_HPP
#define CPP_STACK_HPP

#include <algorithm>
#include <stack>
#include <iostream>

template<typename T>
class Container {
public:
    virtual void push(const T &) = 0;

    virtual void remove(T &) =0;

    virtual size_t size() = 0;
};

template<typename T>
void Container<T>::push(const T &){
        std::cout<< "base push"<< std::endl;
}

template<typename T>
class Stack : public Container<T> {
public:
    Stack() {
        begin_ = new T[realloc_size_];
    }

    ~Stack(){delete begin_;}

    void push(const T &t) override {
        this->Container<T>::push(t);
        *(begin_ + size_++) = t;

        if (size_ >= realloc_size_) {
            realloc();
        }
    }

    void pop() {
        if (size_ > 0)
            size_--;
    }

    T* top() {
        return begin_ + size_ -1;
    }

    bool empty ()
    {
        return size_ ==0;
    }

    size_t size() override {return size_; }

    void remove(T &) override {}

private:
    void realloc() {
        std::cout<<"realloc from "<<realloc_size_<<" to "<<realloc_size_*2<<std::endl;
        T *newBegin = new T[realloc_size_ * 2];
        std::copy(begin_, begin_ + size_, newBegin);
        delete[] begin_;
        begin_ = newBegin;
        realloc_size_ *= 2;
    }

private:
    size_t realloc_size_ = 16;
    size_t size_ = 0;
    T *begin_;
};

#endif //CPP_STACK_HPP
