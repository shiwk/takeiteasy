//
// Created by shiwk on 2021/3/1.
//

#ifndef CPP_UNIVERSAL_REFERENCE_HPP
#define CPP_UNIVERSAL_REFERENCE_HPP
#include <iostream>
#include <string>

void process(int& i){
    std::cout << "process(int&):" << i << std::endl;
}
void process(int&& i){
    std::cout << "process(int&&):" << i << std::endl;
}
void process(const int& i){
    std::cout << "process(const int&):" << i << std::endl;
}
void process(const int&& i){
    std::cout << "process(const int&&):" << i << std::endl;
}


void process(std::string& i){
    std::cout << "process(int&):" << i << std::endl;
}
void process(std::string&& i){
    std::cout << "process(int&&):" << i << std::endl;
}
void process(const std::string& i){
    std::cout << "process(const int&):" << i << std::endl;
}
void process(const std::string&& i){
    std::cout << "process(const int&&):" << i << std::endl;
}

class UniversalReference{
public:
    template<typename T>
    void func(T &&t){
        if (std::is_same<std::string, T&&>::value)
            std::cout << "string " ;
        else if (std::is_same<std::string&, T&&>::value)
            std::cout << "string& " ;
        else if (std::is_same<std::string&&, T&&>::value)
            std::cout << "string&& " ;
        else if (std::is_same<int, T&&>::value)
            std::cout << "int " ;
        else if (std::is_same<int&, T&&>::value)
            std::cout << "int& " ;
        else if (std::is_same<int&&, T&&>::value)
            std::cout << "int&& " ;
        else
            std::cout << "unkown " ;
        std::cout << t << std::endl;
    }

    template<typename T>
    void func(const T &&t){
        std::cout << t << std::endl;
    }

    void myforward(int&& i){
        std::cout << "myforward(int&&):" << i << std::endl;
        process(i); // right ref i is lvaue
    }

    template<typename T>
    void withForward(T&& t){
        process(std::forward<T>(t));
    }

    template<typename T>
    void withoutForward(T&& t){
        std::cout << "t is const T&:" << std::is_same<T, const int &>::value<< std::endl;
        process(t);
    }

    std::string Test(){
        std::string s = std::string("11");
        return std::move(s);
    }
};

#endif //CPP_UNIVERSAL_REFERENCE_HPP
