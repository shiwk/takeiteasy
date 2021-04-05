//
// Created by shiwk on 2021/3/13.
//
#include "container_char.hpp"

template<>
CharStack<char>::CharStack() {
    begin_ = new char[realloc_size_];
}

template<>
CharStack<char>::~CharStack() { delete begin_; }



template<>
void CharStack<char>:: push(const char &t) {
    this->Container::push(t);
    *(begin_ + size_++) = t;

    if (size_ >= realloc_size_) {
        realloc();
    }
}

template<>
size_t CharStack<char>::size() {return size_; }

template<>
void CharStack<char>::pop() {
    if (size_ > 0)
        size_--;
}

template<>
void CharStack<char>::remove(char &) {}

//
//    void pop() {
//        if (size_ > 0)
//            size_--;
//    }
//
//    char* top() {
//        return begin_ + size_ -1;
//    }
//
//    bool empty ()
//    {
//        return size_ ==0;
//    }
//
//    size_t size() override {return size_; }
//
//    void remove(char &) override {}
//
//};