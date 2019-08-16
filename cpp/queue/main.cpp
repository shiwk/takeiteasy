//
// Created by swk on 2019-06-23.
//

#include <iostream>
#include "loopqueue.h"

int main(){

    const int size = 10;
    happycoding::loopqueue queue(size);
    int nums[size] = {1,2,3,4,5,6,7,8,9,10};
    std::cout<< "--- ENQUEUE ---"<<std::endl;
    for (int num : nums) {
        std::cout<<queue.enqueue(num)<<std::endl;
    }
    std::cout<< "--- DEQUEUE ---"<<std::endl;
    int i = 0;
    while(i++ < size * 2 ) {
        try {
            int n = queue.dequeue();
            std::cout<< n << std::endl;
        }
        catch (std::logic_error){
            std::cout<< "Queue is full." << std::endl;
            break;
        }
    }
    std::cout<< "--- ENQUEUE & DEQUEUE ---"<<std::endl;
    int nums1[10] = {1,2,3,4,5,};
    for (int num : nums1) {
        std::cout<<"Enqueue " << num << ":";
        std::string res = queue.enqueue(num) ? "yes" : "no";
        std :: cout << res << std::endl;
        std::cout<<"Dequeue " << queue.dequeue()<< std::endl;
    }
}
