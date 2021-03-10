//
// Created by shiwk on 2021/2/23.
//

#ifndef CPP_VIRTUAL_HPP
#define CPP_VIRTUAL_HPP

#include <iostream>

struct A {
    virtual void f() { std::cout << "A\n"; }

    virtual void f0() const{ std::cout << "A->f0\n"; }

    int a = 1;

    void print() {
        std::cout << "A -> print" << std::endl;
    }

    virtual void fun(int a) {
        std::cout << "A->fun" << std::endl;
    }

    void fun1(int a) {
        std::cout << "A->fun1" << std::endl;
    }
//    A() { this->f(); }
//
//    ~A() { this->f(); }
};


struct B : public A {
    void f() override { std::cout << "B\n"; }

    virtual void f0() const override{ std::cout << "B->f0\n"; }

    int a = 2;

    virtual void fun(char *a) {
        std::cout << "B->fun" << std::endl;
    }

    void print() {
        std::cout << "B -> print" << std::endl;
    }

    void fun1(const char *a) {
        std::cout << "B ->fun1" << std::endl;
    }
//    B() { this->f(); }
//
//    ~B() { this->f(); }
};

#endif //CPP_VIRTUAL_HPP
