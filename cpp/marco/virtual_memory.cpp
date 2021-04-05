//
// Created by shiwk on 2021/3/16.
//

#ifndef CPP_VIRTUAL_MEMORY_CPP
#define CPP_VIRTUAL_MEMORY_CPP
struct Base {
    Base() = default;
    virtual ~Base() = default;

    void FuncA() {}
    virtual void FuncB() {
    }
    int a;
    int b;
};
struct BaseA : virtual public Base {
    BaseA() = default;

    void FuncA() {}
    virtual void FuncB() {
    }
    int a;
    int b;
};
struct BaseB : public Base {
    BaseB() = default;

    void FuncA() {}
//    virtual void FuncC() {
//    }
    int a;
    int b;
};
struct Derive : public BaseB, public BaseA{
    void FuncB() override {
    }
//    void FuncC() override {
//    }
};
#endif //CPP_VIRTUAL_MEMORY_CPP

//int main(){
//    Derive d;
//}