//
// Created by swk on 2019-07-01.
//

#include "mergesort.h"

void happycoding::mergesort::sort(int *nums, int begin, int end) {
    if (end <= begin)
        return;
    sort(nums, begin, (begin + end)/2);
    sort(nums, (begin + end)/2 + 1, end);
    const int size = end - begin +1;
    int res[size];
    int p = begin;
    int q = (begin + end)/2 + 1;
    for (int i = 0; i < size ; i++)
    {
        if (p > (begin + end)/2)
            res[i] = nums[q++];
        else if (q > end)
            res[i] = nums[p++];
        else if(nums[p] > nums[q])
            res[i] = nums[q++];
        else
            res[i] = nums[p++];
    }
    for(int i = 0; i < size; i++)
    {
        nums[i + begin] = res[i];
    }
}