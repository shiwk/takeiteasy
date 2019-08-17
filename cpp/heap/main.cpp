//
// Created by swk on 2019-08-14.
//
#include "heap.hpp"
#include "median.hpp"
#include <random>
#include <iostream>

using namespace std;

void testHeap(int count)
{
    happycoding::Heap<int> heap(false);
    std::random_device rd;
    std::mt19937_64 mt(rd());
    std::uniform_int_distribution<int> dist(0, count);
    cout<< "------Insert-------"<<endl;
    int i = 0;
    while (i++ < count )
    {
        int k = dist(mt);
        heap.add(k);
        cout<< k<<" ";
    }
    cout<<endl;
    cout<< "-------Pop-------"<<endl;

    i = count;
    while (i-- > 0)
    {
        int v = heap.pop();
        cout<< v<<" ";
    }
    cout<<endl;
}


bool testMedianFinder(int count){
    happycoding::MedianFinder<int> medianFinder;
    std::random_device rd;
    std::mt19937_64 mt(rd());
    std::uniform_int_distribution<int> dist(0, count);
    cout<< "------Push-------"<<endl;
    vector<int> nums;
    int i = 0;
    while (i++ < count)
    {
        int k = dist(mt);
        medianFinder.push(k);
        nums.push_back(k);
    }

    sort(nums.begin(), nums.end());
    for (auto t : nums)
    {
        cout << t << " ";
    }
    cout<<endl;
    cout<< "-----Median-----"<<endl;
    cout << nums[(nums.size()-1)/2] << endl;
    cout<< "-----Result-----"<<endl;
    int m = medianFinder.findMedian();
    cout<<m ;

    return m == nums[(nums.size()-1)/2];
}

int main(){
    while (true){
        cout<< "Number count: ";
        int count;
        cin>>count;
        if (count < 0)
            return -1;
        bool res = testMedianFinder(count);
        if(!res)
            return -1;
        cout << endl;
    }
}