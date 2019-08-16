//
// Created by swk on 2019-07-01.
//
#include "quicksort.h"
#include "mergesort.h"
#include <iostream>
#include <random>
using namespace happycoding;
using namespace std;

int main(){
    const int size = 100;
    int* nums = new int[size]{};

    cout<<"-------Before sort------"<<endl;

    std::random_device rd;
    std::mt19937_64 mt(rd());
    std::uniform_int_distribution<int> dist(0, size);

    for (int i = 0; i < size ; i++)
    {
        nums[i] = dist(mt);
        cout << nums[i]<< " ";
    }

    int copy[size];
    for (int j = 0; j < size; ++j) {
        copy[j] = nums[j];
    }

    cout<<endl<<endl;

    cout<<"-------After quick sort------"<<endl;
    quicksort qs;
    qs.sort(nums, 0, size - 1);
    for (int i = 0; i < size ; i++)
    {
        cout << nums[i]<< " ";
    }
    cout<<endl<<endl;


    cout<<"-------After merge sort------"<<endl;
    happycoding::mergesort ms;
    int *nums2 = copy;
    ms.sort(nums2, 0, size -1);
    for (int i = 0; i < size ; i++)
    {
        cout << nums2[i]<< " ";
    }
}