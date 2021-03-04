//
// Created by shiwk on 2021/2/23.
//

#ifndef CPP_POINTER_HPP
#define CPP_POINTER_HPP

#include <iostream>

void print(const int *p) {
    std::cout << "const int * " << *p << std::endl;
}

void print(int *const p) {
    std::cout << "int *const " << *p << std::endl;
}

class Pointer_A {
public:
    Pointer_A() : m1_('c'), m2_(2) {}

    void fun() {
        std::cout << m1_ << "," << m2_ << std::endl;
        std::cout << "========" << std::endl;
    }

private:
    char m1_;
    int m2_;
};

class Pointer_B {
public:
    Pointer_B() : m1_(3) {}

    void fun() {
        std::cout << m1_ << std::endl;
        std::cout << "========" << std::endl;
    }

private:
    int m1_;
};

class Pointer_C {
public:
    Pointer_C() : i(1) {}

    int i;

    void fun() {
        std::cout << i << std::endl;
    }
};

struct S {
    int i;
    char c;
    int *p;
};

class Pointer_D : public Pointer_C {
public:
    Pointer_D() : i(2) {}

    int i;
};

class Pointer {
public:
    explicit Pointer(const int *i) : p(i) { i2_ = *i; }

    const int *GetInt() const { return p; }

    void TestConst() {
        int i = 100;
        const int *p1 = &i;
        int const *p2 = &i;
        int *const p3 = &i;
        const int *const p4 = &i;

        print(p1);
        print(p2);
        print(p3);
        print(p4);
        std::cout << "========" << std::endl;

//        *p1 = 200; // cannot change value by p1
//        *p2 = 200; // cannot change value by p2
        *p3 = 200;
//        *p4 = 200; // cannot change value by p4
        print(p1);
        print(p2);
        print(p3);
        print(p4);
        std::cout << "========" << std::endl;

        i = 300;
        print(p1);
        print(p2);
        print(p3);
        print(p4);
        std::cout << "========" << std::endl;

        p1++;
        p2++;
//        p3++;// cannot change p3 points to
//        p4++;// cannot change p4 points to
    };

    void ConstMethod() const {
        i1_ = 1;
//        i2_ = 1; // const method cannot change un-mutable field
    }

    const char *TestPointer() {
        char const *c1 = "hellohello"; // this "hello" stored in staic memory, so it is still valid outside this function, but it unmutable
        std::cout << &c1 << " " << c1 << " " << &c1[0] << " " << c1[0] << " " << &c1[1] << " " << c1[1] << " " << *c1
                  << " " << std::endl;

        char c2[] = "hello12345"; // this "hello" in stack but mutable
        std::cout << &c2 << " " << c2 << " " << &c2[0] << " " << c2[0] << " " << &c2[1] << " " << c2[1] << " " << *c2
                  << " " << std::endl;
        const char *const c3 = c2;

        const char *c4 = c2;
        char *const c5 = c2;

        const char *const *c6 = &c5;
        std::cout << &c6 << " " << c6 << " " << *c6 << " " << **c6 << std::endl;
        std::cout << &c5 << " " << c5 << " " << *c5 << " " << std::endl;

        const char *c7[3] = {"123", "456", "7890"};
        const char **c8 = c7;
        std::cout << *c8 << " " << c7[0] << " " << **c8 << std::endl;
        c8++;
        std::cout << *c8 << " " << c7[0] << " " << **c8 << std::endl;

        int a = 1;
        int b = 2;
        int c = 3;
        int *i7[3] = {&a, &b, &c};
        int **i8 = i7;
        std::cout << *i8 << " " << i7[0] << " " << &a << std::endl;

        return c1;
    }

    void TestHide() {
        Pointer_D pd;
        pd.fun();
        std::cout << pd.i << std::endl;
        std::cout << "========" << std::endl;
    }

    void TestThisPointer(){
        auto pTHis = this;
        std::cout << &pTHis << " " << pTHis << std::endl;
    }

    void TestPointInvalid() {
        S s;
        int *p = &s.i;
        p[0] = 1;
        p[1] = 300000;
        p[2] = 5;

        std::cout << p[0] << " " << s.i << std::endl;
        std::cout << &p[0] << " " << &s.i << std::endl;

        std::cout << p[1] << " " << s.c << std::endl;
        std::cout << p << " " << &p << " " << &p[1] << " " << &p[2] << " " << &s.p << " " << &s.p[0] << " " << &s.p[1]
                  << std::endl;

        std::cout << "-----------" << std::endl;
        s.p = p;

        std::cout << p[0] << " " << s.i << std::endl;
        std::cout << &p[0] << " " << &s.i << std::endl;

        std::cout << p[1] << " " << s.c << std::endl;
        std::cout << p << " " << &p << " " << &p[1] << " " << &p[2] << " " << &s.p << " " << &s.p[0] << " " << &s.p[1]
                  << std::endl;
        std::cout << "-----------" << std::endl;

        s.p[2] = 7;
        std::cout << p << " " << &p << " " << &p[1] << " " << &p[2] << " " << &s.p << " " << &s.p[0] << " " << &s.p[1]
                  << std::endl;
        s.p[0] = 1;
        std::cout << "-----------" << std::endl;

        std::cout << p << " " << &p << " " << &p[1] << " " << &p[2] << " " << &s.p << " " << &s.p[0] << " " << &s.p[1]
                  << std::endl;
    }

    void TestFuncPointer() {
        void (*func)(const int *);
        func = &print;
        func(&i2_);

        int (*(*F)(int, int))(int *); //F(1,2)(0);
        int (*Func[10])(int); // array of 10 function pointers pointing to int(int) function
    }

    void TestArrayPointer() {
        int v[2][3] = {{1, 2, 3},
                       {4, 5, 6}};
        int (*pointerOfArray)[3];
        pointerOfArray = v;
        std::cout << **pointerOfArray << " " << *(*pointerOfArray + 1) << " " << *(*pointerOfArray + 2) << std::endl;
        std::cout << **(pointerOfArray + 1) << " " << *(*(pointerOfArray + 1) + 1) << " "
                  << *(*(pointerOfArray + 1) + 2) << std::endl;

        int *arrayOfPointer[10] = {v[0], v[1]};
        std::cout << *arrayOfPointer[0] << " " << *(arrayOfPointer[0] + 1) << " " << *(arrayOfPointer[0] + 2)
                  << std::endl;
        std::cout << *arrayOfPointer[1] << " " << *(arrayOfPointer[1] + 1) << " " << *(arrayOfPointer[1] + 2)
                  << std::endl;

        int *p = reinterpret_cast<int *>(&v + 1);
        std::cout << v << " " << p << " " << *(p - 1) << std::endl;
    }

    void TestDanglingPointer() {
        int a;
        int *i = new int;
        delete i;
        i = nullptr;
        std::cout << &i << " " << i << std::endl;
        long *l = new long;
        *l = 10;
        std::cout << *l << std::endl;

        *i = 3; //EXC_BAD_ACCESS exception
        std::cout << *i << std::endl;

        delete l;
    }

private:
    const int *const p;
    mutable int i1_;
    int i2_;
};

#endif //CPP_POINTER_HPP
