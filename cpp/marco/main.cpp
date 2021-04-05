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
#include "dummy.hpp"
#include "nrvo.hpp"
#include "share_ptr.hpp"
#include "container_char.hpp"

void point() {
    int i = 100;
    Pointer p(&i);
    std::cout << &p << std::endl;
    p.TestThisPointer();

    int &j = i;
//    const int &k = i;
    const int &k = 100;
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
    aa.f0(0);
    A a1 = b;
    a1.f0(1);
    a1.print(2);

    A *a = &b;

    a->f(1); // b
    a->f0(1); // a
    a->print(2); // a
    a->fun(3); // a
    b.fun("cc"); // b
    a->fun1(2); // a
    b.fun1("cc"); //b

    std::cout << "==========" << std::endl;
    A *a2 = &a1;
    a2->print(3); //a
    //B *b2 = dynamic_cast<B *>(a2); // downcasting returns 0
//    b2->f0(4);
//    b2->print(5);
    B *bb = &b;
    A *a3 = dynamic_cast<A *>(bb); // upcasting is ok

    std::cout << a3 << std::endl;
    std::cout << bb << std::endl;

    a3->f(5); // b
    a3->f0(6); // a
    a3->print(7); //a

    A a4;
    B *b3 = dynamic_cast<B *>(&a4);// b3 is NULL
    std::cout << b3 << std::endl; // 0x0

    B *b5 = (B *) (&a4);
    b5->fun1("cc");

    std::cout << "==========" << std::endl;
    C c;
    A *ca = &c;
    B *cb = dynamic_cast<B *>(ca);
    cb->f(7);
    cb->f0(7);
    cb->print(7);

    C *bc = dynamic_cast<C *>(&a4);// bc is NULL
    std::cout << bc << std::endl; // 0x0

    std::cout << "==========" << std::endl;

    b.f0(8);
    b.A::f0(9);

    b.f(8);
    b.A::f(9);

    b.print(10);
    b.A::print(11);
    B *b1 = &b;
    b1->print(12);
    std::cout << "==========" << std::endl;

    auto a5 = dynamic_cast<A *>(a);
    std::cout << typeid(a5).name() << std::endl;
    std::cout << typeid(b).name() << std::endl;

    E e;
    e.f(10);
    e.C::f(10);
    e.D::f(10);
    B *ae = dynamic_cast<D *>(&e);
    ae->f(10);

    C *cc = dynamic_cast<C *>(&e); //
    std::cout << "cc :" << cc << std::endl;

    EE *ee = new EE();
    cc = dynamic_cast<C *>(ee);
    std::cout << "cc :" << cc << std::endl;

    FF ff;
    FF *ffp = &ff;
    C *cffp = &ff;
    std::cout << ffp << std::endl;
    std::cout << cffp << std::endl;

//    GGG *ggg  = dynamic_cast<GGG*>(ff); //FF' is not polymorphic
//    std::cout << "ff :" << ff << std::endl;


    std::cout << "==========" << std::endl;
    HHHH h;
    std::cout << "==========" << std::endl;

    std::cout << "A size: " << sizeof(A) << std::endl;
    std::cout << "B size: " << sizeof(B) << std::endl;
    std::cout << "C size: " << sizeof(C) << std::endl;
    std::cout << "D size: " << sizeof(D) << std::endl;
    std::cout << "E size: " << sizeof(E) << std::endl;
    std::cout << "EE size: " << sizeof(EE) << std::endl;
    std::cout << "F size: " << sizeof(F) << std::endl;
    std::cout << "FF size: " << sizeof(FF) << std::endl;
    std::cout << "G size: " << sizeof(G) << std::endl;
    std::cout << "GG size: " << sizeof(GG) << std::endl;
    std::cout << "GGG size: " << sizeof(GGG) << std::endl;
    std::cout << "H size: " << sizeof(H) << std::endl;
    std::cout << "HH size: " << sizeof(HH) << std::endl;
    std::cout << "HHH size: " << sizeof(HHH) << std::endl;
    std::cout << "HHHH size: " << sizeof(HHHH) << std::endl;

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

    CharStack<char> cs;
    cs.push('c');
    cout << "char stack size: " << cs.size();

//    CharStack<int> cs1; // link error, since CharStack<int> not defined symbols
//    cs1.push(1);
//    cout<<"char stack size: " << cs.size();
};


void testOObject() {
    String s1("abc");
    String s2 = s1;

    const char *c = "hello";
    s1.Write(c);
    s1.Print();
    s2.Print();

    s1.Print(String("edf"));
    String str("ppp");
    s1.Print(str);
    String s3((String("zzz")));
    String s4(String("123"));
    s4.Print();
    s3.Print();

    String s5;
    s5 = s3.Me();
    String s6 = std::move(String("qqq"));

    char *c1 = static_cast<char *>(s5);
    int i1 = static_cast<int>(s5);
    int i2 = (int) s5;
    ++s5;
    s5.Print();
    s5++;
    s5.Print();

    String s7 = s5 + s6;
    s7.Print();

    String *s8 = ::new String();
    String::operator delete(s8, "abc");
    String *s9 = new String("abc");
    cout << "s9[0] = " << (*s9)[0] << endl;
    s9->Print();
    s7->TestStaticField();
    String::operator delete(s9, "zx");

    String &s10 = s3;
    cout<< "&s10: " <<&s10<<endl;
    cout<< "&s5: " <<&s5<<endl;
    s10.Print();
    s5.Print();

    s10 = s5;
    cout<< "&s10: " <<&s10<<endl;
    cout<< "&s5: " <<&s5<<endl;
    s10.Print();
    s5.Print();
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

void testVfptr() {
    Y y;
    Y *yy = &y;
    X *xy = yy;
    typedef void(*P)();
    cout << yy << endl;
    cout << (&y) + 8 << endl;
    cout << xy << endl;
    cout << &(xy->x) << endl;
//    cout << *(long int *) (yy) << endl;
//    cout<<*(long int *) (x + 8)<<endl;
//    cout << *(long int *) (yy) + 8 << endl;

    ((P) (*(long int *) *(long int *) (yy)))();
    ((P) (*((long int *) *(long int *) (yy) + 1)))();
    ((P) (*(long int *) (*(long int *) (yy) + 8)))();

    ((P) (*(long int *) *(long int *) (xy)))();
}

void testCallStack() {
    func(1, 2);
}


void testNrvo() {
    cout << "*** 1 ***" << endl;
    auto obj1 = simple();
    cout << "*** 2 ***" << endl;
    auto obj2 = simple_with_move();
    cout << "*** 3 ***" << endl;
    auto obj3 = complicated(42);
    cout << "*** end ***" << endl;

}

void sharePtrTest() {
    shared_ptr<Node<int>> sp1(new Node<int>(1));
    shared_ptr<Node<int>> sp2(new Node<int>(2));

    cout << "sp1.use_count:" << sp1.use_count() << endl;
    cout << "sp2.use_count:" << sp2.use_count() << endl;

    sp1->_pNext = sp2; //sp2 ptr count +1
    cout << "sp1.use_count:" << sp1.use_count() << endl;
    cout << "sp2.use_count:" << sp2.use_count() << endl;

    sp2->_pPre = sp1; //sp1 ptr count +1
    cout << "sp1.use_count:" << sp1.use_count() << endl;
    cout << "sp2.use_count:" << sp2.use_count() << endl;
}

void offsetofObject() {
    cout << offsetof(StructS, x) << endl; // 0
    cout << offsetof(StructS, y) << endl; // 4
    cout << offsetof(StructS, z) << endl; // 8
    cout << offsetof(StructS, a) << endl; // 12
}

int main() {
    try {
        testOObject();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}