//
// Created by shiwk on 2021/3/11.
//

#ifndef CPP_MINNUMBERINROTATEARRAY_HPP
#define CPP_MINNUMBERINROTATEARRAY_HPP

#include <vector>

using namespace std;

class MinNumberInRotateArray {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int start = 0;
        int end = rotateArray.size() - 1;

        if (rotateArray[start] < rotateArray[end])
            return rotateArray[start];
        int med_k;
        while (true) {
            if (start + 1 == end)
            {
                med_k = rotateArray[start] < rotateArray[end] ? rotateArray[0]:rotateArray[end];
                break;
            }
            int med = start + end >> 1;
            med_k = rotateArray[med];

            if (rotateArray[start] == med_k && rotateArray[end] == med_k)
                return min(rotateArray);

            if (med_k >= rotateArray[start])
                start = med;
            else
                end = med;
        }

        return med_k;

    }

    int min(vector<int>& array){
        int m = array.front();
        for(int i:array)
        {
            m = m < i ? m:i;
        }
        return m;
    }
};

#endif //CPP_MINNUMBERINROTATEARRAY_HPP
