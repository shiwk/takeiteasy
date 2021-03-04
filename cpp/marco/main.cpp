//
// Created by shiwk on 2021/2/22.
//


#include "marco.hpp"
#include "pointer.hpp"
#include "sizeof.hpp"
#include "virtual.hpp"
#include "vector.hpp"
#include "container.hpp"
#include "oobject.hpp"
#include "universal_reference.hpp"
#include <iostream>
#include <exception>
#include <string>

void point() {
    int i = 100;
    Pointer p(&i);
    std::cout << &p << std::endl;
    p.TestThisPointer();
}

void testSizeOf() {
    SizeOf size_of;
    size_of.TestCharSize();
    size_of.TestStructSize();
    size_of.TestIntSize();
    size_of.TestStringSize();
    size_of.TestClassSize();
}

void testVirtual() {
    B b;
    A &aa = b;
    aa.f0();
    A a1 = b;
    a1.f0();
    a1.print();

    A *a = &b;
    a->f0();
    a->print();
    a->fun(1);
    b.fun("cc");
    a->fun1(1);
    b.fun1("cc");

    std:: cout<<"=========="<<std::endl;
    A *a2 = &a1;
    a2->print();
    B *b2 = (B*)a2;
    b2->f0();
    b2->print();
    B *bb =&b;
    A *a3 = dynamic_cast<A *>(bb);
    std::cout<<a3<<std::endl;
    std::cout<<bb<<std::endl;

    a3->f0();
    a3->print();

    A a4;
    B *b3 = dynamic_cast<B*>(&a4);// b3 is NULL
    std::cout<<b3<<std::endl; // 0x0

    B* b5 = (B*)(&a4);
    b5->fun1("cc");

    auto a5 = dynamic_cast<A*>(bb);
    std:: cout<<"=========="<<std::endl;

    b.f0();
    b.A::f0();

    b.print();
    b.A::print();
    B *b1 = &b;

    b1->print();
    std:: cout<<"=========="<<std::endl;

    std::cout<< typeid(a5).name()<<std::endl;
    std::cout<< typeid(b).name()<<std::endl;
}

void testVector() {
    VectorTester vt;
    vt.TestElementCopyPush();
}

void TestStack() {
    Stack<int> s;
    std::cout << s.size() << std::endl;
    std::cout << *s.top() << std::endl;
    std::cout << s.top() << std::endl;

    std::cout << "=====" << std::endl;
    for (int i = 1; i <= 16; ++i) {
        s.push(i);
        std::cout << *s.top() << std::endl;
        std::cout << "size: " << s.size() << std::endl;
    }
    std::cout << s.top() << std::endl;

    std::cout << "=====" << std::endl;

    for (int i = 1; i <= 16; ++i) {
        s.pop();
        std::cout << *s.top() << std::endl;
        std::cout << "size: " << s.size() << std::endl;
    }
    std::cout << "=====" << std::endl;
    std::cout << s.top() << std::endl;


    for (int i = 1; i <= 32; ++i) {
        s.push(i);
        std::cout << *s.top() << std::endl;
        std::cout << "size: " << s.size() << std::endl;
    }
    std::cout << "=====" << std::endl;

    for (int i = 1; i <= 32; ++i) {
        std::cout << *s.top() << std::endl;
        s.pop();
        std::cout << "size: " << s.size() << std::endl;
    }
};


void testOObject() {
    String s1("abc");
    String s2 = s1;

    const char *c = "hello";
    s1.Write(c);
    s1.Print();
    s2.Print();

    s1.Print(String("edf"));
    String s3(std::move((String("zzz"))));
    String s4(String("123"));
    s4.Print();
    s3.Print();

    String s5;
    s5 = s3.Me();
    String s6;
    s6 = std::move(String("qqq"));

    char *c1 = static_cast<char*>(s5);
    int i1 = static_cast<int>(s5);
    int i2 =(int) s5;
    ++s5;
    s5.Print();
    s5++;
    s5.Print();

    String s7 = s5  + s6;
    s7.Print();
}

void testUniversal() {
    UniversalReference ur;
    ur.func(10); // rvalue
    int x = 10;
    ur.func(x); //lvaue

    int &&a = 3;
    ur.func(a); //&& right ref a is lvaue

    std::string str = "hello";
    ur.func(str); //lvaue
    ur.func(std::move(str)); //rvaue
    ur.func(std::string("hi")); //rvaue

    ur.withoutForward(11);
    int i1 = 12;
    ur.withoutForward(i1);
    std::string str1 = "he";
    ur.withoutForward(std::move(str1));
    const int i2 = 13;
    ur.withoutForward(i2);
    ur.withoutForward(std::move(i2));
    std::cout << "===========" << std::endl;

    ur.withForward(13);
    int i3 = 14;
    ur.withForward(i3);
    ur.withForward(std::move(i3));
    const int i4 = 15;
    ur.withForward(i4);
    ur.withForward(std::move(i4));
}


int main() {
    try {
        testVirtual();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}