//
// Created by shiwk on 2021/2/25.
//

#ifndef CPP_VECTOR_HPP
#define CPP_VECTOR_HPP

#include <cstring>
#include <iostream>
#include <vector>

class Element{
public:
    int *c;

//    Element(const Element &e)  = default; // default copy constructor : c points to the same memory
    Element(const Element &e) {
        c = new int(*e.c);
    } // reimplemented copy constructor

    Element(int *c) : c(c) {}

    ~Element(){
        std::cout<<c<<std::endl;
        std::cout<<"Deconstruct element."<<std::endl;
        delete c;
    }
};

class VectorTester{
public:
    void TestElementCopyPush(){
//        int i = 1;
        int *p = new int;
        Element e(p);
        e.c = p;
        std::cout<<*e.c<<std::endl;

        std::vector<Element> *elements = new std::vector<Element>();
        elements->push_back(e);

        std::cout<< e.c << " " <<elements->front().c <<std::endl;
        std::cout<< "ok" <<std::endl;

        delete elements;
    }
};
#endif //CPP_VECTOR_HPP
