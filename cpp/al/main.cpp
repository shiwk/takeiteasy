//
// Created by shiwk on 2021/3/3.
//

#include "FindRepeated.hpp"
#include "ReplaceWhitespace.hpp"
#include "LinkList.hpp"
#include <iostream>
using namespace std;
void findRepeated(){
    FindRepeated find_repeated;
    vector<int> arr = {6,4,2,6,2,5,3};
    cout<<find_repeated.find(arr);
}

void replaceWhitespace(){
    string str("hell  o");
    ReplaceWhiteSpace rw;
    cout<<rw.replaceSpace(str);
}

void ReverseLinkList(){
    ListNode node1(1);
    ListNode node2(2);
    node1.next = &node2;
    ListNode node3(3);
    node2.next = &node3;
    ListNode node4(4);
    node3.next = &node4;

    LinkList ll;
    vector<int> res = ll.printListFromTailToHead2(&node1);
    for (auto i:res) {
        cout<<i<<endl;
    }
}
int main(){
    ReverseLinkList();
}