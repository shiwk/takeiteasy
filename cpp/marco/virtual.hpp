//
// Created by shiwk on 2021/2/23.
//

#ifndef CPP_VIRTUAL_HPP
#define CPP_VIRTUAL_HPP

#include <iostream>

struct A {
    virtual void f(int i) { std::cout << "A->f: "<< i << std::endl; }

    virtual void f0(int i) const{ std::cout << "A->f0: "<< i << std::endl; }

    int a = 1;

    void print(int i) {
        std::cout << "A -> print: "<< i << std::endl;
    }

    virtual void fun(int i) {
        std::cout << "A->fun: " << i<< std::endl;
    }

    void fun1(int i) {
        std::cout << "A->fun1: "<< i << std::endl;
    }
//    A() { this->f(); }
//
//    ~A() { this->f(); }
};


struct B : public A {
    void f(int i) override { std::cout << "B->f: "<< i << std::endl; }

    virtual void f0(int i) { std::cout << "B->f0: "<< i << std::endl; }

    int a = 2;

    virtual void fun(char *a) {
        std::cout << "B->fun:" << a <<std::endl;
    }

    void print(int i) {
        std::cout << "B -> print: "<< i << std::endl;
    }

    void fun1(const char *a) {
        std::cout << "B ->fun1: " <<a<< std::endl;
    }
    void fun2(const char *a) {
        std::cout << "B ->fun1: " <<a<< std::endl;
    }
//    B() { this->f(); }
//
//    ~B() { this->f(); }
};

struct C: public B{
    void f(int i) override { std::cout << "C->f: "<< i << std::endl; }
};

#endif //CPP_VIRTUAL_HPP
