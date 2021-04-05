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
    A() { std::cout << "A Constructor."<<std::endl; }
//
//    ~A() { this->f(); }
};


struct B : public A {
    void f(int i) override { std::cout << "B->f: "<< i << std::endl; }

    virtual void f0(int i) { std::cout << "B->f0: "<< i << std::endl; }
    virtual void f1(int i) { std::cout << "B->f1: "<< i << std::endl; }

    int a = 2;
    int b = 2;

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
    B() { std::cout << "B Constructor."<<std::endl; }
//
//    ~B() { this->f(); }
};

struct  C: B{
    void f(int i) override { std::cout << "C->f: "<< i << std::endl; }
    C() { std::cout << "C Constructor."<<std::endl; }
    int c;
};


struct D: B{
    void f(int i) override { std::cout << "D->f: "<< i << std::endl; }
    D() { std::cout << "D Constructor."<<std::endl; }
};

struct E : virtual C, virtual D{
    void f(int i) override { std::cout << "E->f: "<< i << std::endl; }
};

struct EE : C, D{
//    void f(int i) override { std::cout << "E->f: "<< i << std::endl; }
};
#endif //CPP_VIRTUAL_HPP


struct F {
    virtual void f(int i) { std::cout << "F->f: "<< i << std::endl; }
    virtual void f1(int i) { std::cout << "F->f1: "<< i << std::endl; }
    int i;
    int j;
};

struct FF : virtual C{
    void f(int i) { std::cout << "F->f: "<< i << std::endl; }
    virtual void f2(int i) { std::cout << "F->f: "<< i << std::endl; }
    int ff;
};

struct G : F{

};

struct GG : virtual F{

};

struct GGG : virtual FF{

};


struct H {
    H() { std::cout << "H Constructor."<<std::endl; }
    void f(int i) { std::cout << "H->f: "<< i << std::endl; }
    int h;
};

struct HH : virtual H{
    void f(int i) { std::cout << "HH->f: "<< i << std::endl; }
    HH() { std::cout << "HH Constructor."<<std::endl; }
};

struct HHH : virtual H{
    void f(int i) { std::cout << "HHH->f: "<< i << std::endl; }
    HHH() { std::cout << "HHH Constructor."<<std::endl; }
};

struct HHHH : HH, HHH{
    HHHH() { std::cout << "HHHH Constructor."<<std::endl; }
};

class  X
{
public:
     void test(){
        std::cout << "test X" <<std:: endl;
    }

    int x;
};
class Y :virtual public X
{
public:
     void test(){
        std::cout << "test Y" << std::endl;
    }
//    virtual void test2(){
//        std::cout << "test2 Y" <<std:: endl;
//    }
    int y;
};