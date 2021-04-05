//
// Created by shiwk on 2021/3/14.
//

#ifndef CPP_CUTROPE_HPP
#define CPP_CUTROPE_HPP

class CutRope {
public:
    int cutRope(int number) {
        if (number <= 2)
            return 1;

        int arr[number + 1];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;

        for (int i = 3; i <= number; ++i) {
            int max = 0;
            for (int j = 1; j <= i / 2; ++j) {
                int mul = (j > arr[j] ? j : arr[j]) * (i - j > arr[i - j] ? i - j : arr[i - j]);
                max = max >= mul ? max : mul;
            }
            arr[i] = max;
        }

        return arr[number];
    }
};

#endif //CPP_CUTROPE_HPP
