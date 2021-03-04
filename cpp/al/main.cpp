//
// Created by shiwk on 2021/3/3.
//

#include "FindRepeated.hpp"
#include <vector>
#include <iostream>
using namespace std;
void findRepeated(){
    FindRepeated find_repeated;
    vector<int> arr = {6,4,2,6,2,5,3};
    cout<<find_repeated.find(arr);
}

int main(){
    findRepeated();
}