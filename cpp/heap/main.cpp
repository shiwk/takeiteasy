//
// Created by swk on 2019-08-14.
//
#include "heap.hpp"
#include <random>
#include <iostream>

using namespace std;

int main(){
    heap<int> heap(false);
    const int n = 100;
    std::random_device rd;
    std::mt19937_64 mt(rd());
    std::uniform_int_distribution<int> dist(0, n);
    cout<< "------Insert-------"<<endl;
    int i = 0;
    while (i++ < n )
    {
        int k = dist(mt);
        heap.add(k);
        cout<< k<<" ";
    }
    cout<<endl;
    cout<< "-------Pop-------"<<endl;

    i = n;
    while (i-- > 0)
    {
        int v = heap.pop();
        cout<< v<<" ";
    }
    cout<<endl;
}