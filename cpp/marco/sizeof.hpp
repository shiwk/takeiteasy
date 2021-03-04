//
// Created by shiwk on 2021/2/23.
//

#ifndef CPP_SIZEOF_HPP
#define CPP_SIZEOF_HPP
#include <iostream>
#include <string>

struct StructA {
    int i;
    char c;
    float f;
};

class ClassA {
private:
    int i;
    char c;
    float f;
};

class Base {
    virtual void foo(){}

};

class ChildA : public Base{

};

class ChildB : public virtual Base{
    virtual void foo(){}
};

class ChildC : public ChildB{

};

class ChildD : public ChildB{
    virtual void foo(){}
};


class ChildE : public ChildA, ChildB{
    virtual void foo(){}
};


class SizeOf {
public:
    void TestCharSize() {
        std::cout<<"char:"<<sizeof(char)<<std::endl;
        std::cout<<"char*:"<<sizeof(char*)<<std::endl;


        char c1[] = "1234";
        std::cout<<"c1:"<<sizeof(c1)<<std::endl;
        std::cout<<"strlen c1:"<<strlen(c1)<<std::endl;
        std::cout<<"*c1:"<<sizeof(*c1)<<std::endl;

        char c2[5] = "1234";
        std::cout<<"c2:"<<sizeof(c2)<<std::endl;
        std::cout<<"strlen c2:"<<strlen(c2)<<std::endl;
        std::cout<<"*c2:"<<sizeof(*c2)<<std::endl;

        char *c3 = c2;
        std::cout<<"c3:"<<sizeof(c3)<<std::endl;
        std::cout<<"strlen c3:"<<strlen(c3)<<std::endl;
        std::cout<<"*c3:"<<sizeof(*c3)<<std::endl;

        char c4[2][5] = {"1234", "12\n"};
        std::cout<<"c4:"<<sizeof(c4)<<std::endl;
//        std::cout<<"strlen c4:"<<strlen(c4)<<std::endl; // strlen only for char[]/char*
        std::cout<<"*c4:"<<sizeof(*c4)<<std::endl;

        std::cout<<std::endl;
    }

    void TestIntSize(){
        int i1 = 0;
        int i2[2] = {1};
        int *i3 = &i1;
        std::cout<<"int:"<<sizeof(int)<<std::endl;
        std::cout<<"int*:"<<sizeof(int*)<<std::endl;

        std::cout<<"i1:"<<sizeof(i1)<<std::endl;
        std::cout<<"i2:"<<sizeof(i2)<<std::endl;
        std::cout<<"i3:"<<sizeof(i3)<<std::endl;
        std::cout<<std::endl;
    }

    void TestStringSize(){
        std::string s1 = "abcde";
        std::string s2[2] = {"abcde"};
        std::string *s3 = &s1;

        std::cout<<"string:"<<sizeof(std::string)<<std::endl;
        std::cout<<"string*:"<<sizeof(std::string*)<<std::endl;

        std::cout<<"s1:"<<sizeof(s1)<<std::endl;
        std::cout<<"s1.size:"<<s1.size()<<std::endl;
        std::cout<<"s2:"<<sizeof(s2)<<std::endl;
        std::cout<<"s3:"<<sizeof(s3)<<std::endl;
        std::cout<<"s3.size:"<<s3->size()<<std::endl;
        std::cout<<std::endl;
    }

    void TestStructSize(){
        std::cout<<"StructA size: "<< sizeof(StructA)<<std::endl;
        std::cout<<"ClassA size: "<< sizeof(ClassA)<<std::endl;
        std::cout<<std::endl;
    }

    void TestClassSize(){
        std::cout<<"Class Base size: "<< sizeof(Base)<<std::endl;
        std::cout<<"ChildA size: "<< sizeof(ChildA)<<std::endl;
        std::cout<<"ChildB size: "<< sizeof(ChildB)<<std::endl;
        std::cout<<"ChildC size: "<< sizeof(ChildC)<<std::endl;
        std::cout<<"ChildD size: "<< sizeof(ChildD)<<std::endl;
        std::cout<<"ChildE size: "<< sizeof(ChildE)<<std::endl;
        std::cout<<std::endl;
    }

};

#endif //CPP_SIZEOF_HPP
