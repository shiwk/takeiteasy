//
// Created by swk on 2019-06-15.
//

#include <iostream>
#include <math.h>

int main(){
    double d = 1;
    double l1 = 365;
    int num = 22;
    while (l1 != 365 - num){
        d *= (l1-- / 365);
    }

    std::cout << std::endl;
    std :: cout << 1 - d << std :: endl;
}