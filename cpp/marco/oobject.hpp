//
// Created by shiwk on 2021/2/26.
//

#ifndef CPP_OOBJECT_HPP
#define CPP_OOBJECT_HPP

#include <iostream>
#include <mutex>

struct OOA {
public:
    const static int staticField = 1; // should be defined out of line, if non-const static
    static int staticField2; // should be defined out of line, if non-const static
//    static std::mutex staticField3; // should be defined out of line, if non-const static
    void TestStatic(){
        // !! TestStatic link will fail if staic fields not defined
        int i = staticField;
        int j = staticField2;
//        std::unique_lock<std::mutex> lock(staticField3);
    }
};

int OOA::staticField2 = 1;

class OObject {
public:
    void TestStaticField() {
        std::cout << OOA::staticField << std::endl;
        OOA ooa;
        ooa.TestStatic();
    }
};


class String {
private:
    char *c_;
public:

    String() {
        c_ = new char[3];
    }

    String(const char *c) {
        std::cout << "common. ";
        int len = strlen(c);
        c_ = new char[len];
        strcpy(c_, c);
        std::cout << c_ << std::endl;
    }

    void Print() {
        std::cout << "Print " << c_ << std::endl;
    }

    String Me() { return {"Me"}; }

    // copy constructor
    String(const String &string) {
        std::cout << "copy constructor!" << std::endl;
        int len = strlen(string.c_);
        c_ = new char[len];
        strcpy(c_, string.c_);
        std::cout << c_ << std::endl;
    }

    String &operator=(const String &string) {
        if (this == &string) // handle self-assigment!!
            return *this;
        std::cout << "copy assignment! ";
        int len = strlen(string.c_);
        c_ = new char[len];
        strcpy(c_, string.c_);
        std::cout << c_ << std::endl;
        return *this;
    }

    String &operator=(String &&string) noexcept {
        if (this == &string) // handle self-assigment!!
            return *this;
        std::cout << "move assignment! ";
        int len = strlen(string.c_);
        c_ = new char[len];
        strcpy(c_, string.c_);
        std::cout << c_ << std::endl;
        string.c_ = nullptr;
        return *this;
    }

    // move constructor
    String(String &&string) noexcept {
        std::cout << "move constructor! ";
        int len = strlen(string.c_);
        c_ = new char[len];
        strcpy(c_, string.c_);
        std::cout << c_ << std::endl;
        string.c_ = nullptr;
    }

    void Print(String &&string) {
        std::cout << "rval reference! ";
        int len = strlen(string.c_);
        c_ = new char[len];
        strcpy(c_, string.c_);
        std::cout << c_ << std::endl;
    }

    void Print(const String &string) {
        std::cout << "const String reference! ";
        int len = strlen(string.c_);
        c_ = new char[len];
        strcpy(c_, string.c_);
        std::cout << c_ << std::endl;
    }


    void Write(const char *c) {
        strcpy(c_, c);
    }

    char *Get() const { return c_; }
//    void* operator new(size_t t) = delete;

    explicit operator char *();

    explicit operator int();

    void operator++();

    void operator++(int);

//private:
    void *operator new(size_t);

    void* operator new(size_t, const char*);

    void operator delete(void *, const char *);
    void operator delete(void *);

    char &operator[](int offset);

    OObject *operator->(); // for member access, not overload on pointer
};

String::operator char *() {
    return c_;
}

String::operator int() {
    return *c_;
}

void String::operator++() {
    *c_ = ++(*c_);
}

void String::operator++(int) {
    *c_ = (*c_)++;
}

void *String::operator new(size_t t) {
    std::cout << "Overloading new operator with size: " << t << std::endl;
    return ::new String();
}

void *String::operator new(size_t t, const char*c) {
    std::cout<< "Overloading new operator with size: " << t <<std::endl;
    return ::new String(c);
}

void String::operator delete(void *p, const char *c) {
    std::cout << "Overloading delete operator " << c << std::endl;
    free(p);
}

void String::operator delete(void *p) {
    std::cout << "Overloading delete operator " << std::endl;
    free(p);
}

OObject *String::operator->() {
    return new OObject;
}

char &String::operator[](int offset) {
    return c_[offset];
}


String operator+(const String &str1, const String &str2) {
    String s;
    char *c = new char[strlen(str1.Get()) + strlen(str2.Get()) + 1];
    strcpy(c, str1.Get());
    strcpy(c + strlen(str1.Get()), str2.Get());
    s.Write(c);
    return s;
}

//void* String::operator new(size_t t)=delete;
#endif //CPP_OOBJECT_HPP
