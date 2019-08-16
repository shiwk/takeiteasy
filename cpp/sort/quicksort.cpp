//
// Created by swk on 2019-07-01.
//

#include "quicksort.h"

void happycoding::quicksort::sort(int *nums, int begin, int end) {
    if(end <= begin)
        return;
    int head = nums[begin];

    int p = begin + 1;
    int q = end;

    while (p <= q){

        while (p <= q)
        {
            if(nums[p] <= head)
                p++;
            else
                break;
        }

        while (p <= q){
            if(nums[q] >= head)
                q--;
            else
                break;
        }

        if (p <= q)
        {
            int tmp = nums[p];
            nums[p] = nums[q];
            nums[q] = tmp;
        }
    }

    nums[begin] = nums[q];
    nums[q] = head;
    sort(nums, begin, q - 1);
    sort(nums, q + 1, end);
}