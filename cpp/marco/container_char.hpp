//
// Created by shiwk on 2021/3/13.
//

#ifndef CPP_CONTAINER_CHAR_HPP
#define CPP_CONTAINER_CHAR_HPP
#include "container.hpp"
template<typename T>
class CharStack : public Container<T> {
public:
    CharStack();
    ~CharStack();
    void push(const T &) override;
    void remove(T &) override;
    void pop();
    size_t size() override;

private:
    void realloc() {
        std::cout<<"realloc from "<<realloc_size_<<" to "<<realloc_size_*2<<std::endl;
        char *newBegin = new char[realloc_size_ * 2];
        std::copy(begin_, begin_ + size_, newBegin);
        delete[] begin_;
        begin_ = newBegin;
        realloc_size_ *= 2;
    }

private:
    size_t realloc_size_ = 16;
    size_t size_ = 0;
    char *begin_;
};
#endif //CPP_CONTAINER_CHAR_HPP
