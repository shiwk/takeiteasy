//
// Created by shiwk on 2021/3/12.
//

#ifndef CPP_FIBONACCI_HPP
#define CPP_FIBONACCI_HPP

class Fibonacci{
public:
    int fibonacci(int n) {
        if (n==0)
            return 0;
        if (n <= 2)
            return 1;

        int i=1;
        int j=1;
        int r = 0;
        for (int k = 3; k <= n; ++k) {
            r = i+j;
            i = j;
            j=r;
        }
        return r;
    }
};
#endif //CPP_FIBONACCI_HPP
