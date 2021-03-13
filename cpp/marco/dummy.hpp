//
// Created by shiwk on 2021/3/5.
//

#include <iostream>
int duplicate(int n)
{
    std::cout<< n<<std::endl;
    return n * 2;
}

//auto Static_A = duplicate(7); // A is dynamic-initialized

int& Static_func_A()
{
    static auto a = duplicate(7); // Initiliazed first time A() is called
    return a;
}

int f(int n)
{
    std::cout << n << std::endl;
    return n;
}

void func(int param1, int param2)
{
    int var1 = param1;
    int var2 = param2;
    printf("var1=%d,var2=%d", f(var1), f(var2));
}