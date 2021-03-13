//
// Created by shiwk on 2021/3/3.
//

#include "FindRepeated.hpp"
#include "ConstructBinaryTree.hpp"
#include "ReplaceWhitespace.hpp"
#include "LinkList.hpp"
#include "MinNumberInRotateArray.hpp"
#include "Queue.hpp"
#include "HasPath.hpp"
#include <iostream>

using namespace std;

void findRepeated() {
    FindRepeated find_repeated;
    vector<int> arr = {6, 4, 2, 6, 2, 5, 3};
    cout << find_repeated.find(arr);
}

void replaceWhitespace() {
    string str("hell  o");
    ReplaceWhiteSpace rw;
    cout << rw.replaceSpace(str);
}

void ReverseLinkList() {
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
        cout << i << endl;
    }
}

void reconstructTree() {
    vector<int> pre = {1, 2, 4, 3, 5, 6};
    vector<int> vin = {4, 2, 1, 5, 3, 6};
    ConstructBinaryTree construct_binary_tree;
    TreeNode *node = construct_binary_tree.reConstructBinaryTree(pre, vin);
}

void testStackQueue() {
    Queue queue;
    queue.push(1);
    queue.push(2);
    cout << queue.pop() << endl;
    queue.push(3);
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
}

void minNumberInRotateArray() {
    MinNumberInRotateArray m;
    vector<int> nums = {6501, 6828, 6963, 7036, 7422, 7674, 8146, 8468, 8704, 8717, 9170, 9359, 9719, 9895, 9896, 9913,
                        9962, 154, 293, 334, 492, 1323, 1479, 1539, 1727, 1870, 1943, 2383, 2392, 2996, 3282, 3812,
                        3903, 4465, 4605, 4665, 4772, 4828, 5142, 5437, 5448, 5668, 5706, 5725, 6300, 6335};
    cout << m.minNumberInRotateArray(nums);
}

void hasPath() {
    string matrix = "ABCESFCSADEE";
    string str = "ABCCED";
    HasPath has_path;
    cout << has_path.hasPath(matrix, 3, 4, str);
}

int main() {
    hasPath();
}