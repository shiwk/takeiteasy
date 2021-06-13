//
// Created by shiwk on 2021/3/3.
//

#include "FindRepeated.hpp"
#include "ConstructBinaryTree.hpp"
#include "ReplaceWhitespace.hpp"
#include "LinkList.hpp"
#include "MinNumberInRotateArray.hpp"
#include "SimpleQueue.hpp"
#include "HasPath.hpp"
#include "CutRope.hpp"
#include "MinCost.hpp"
#include "AL.hpp"
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
    SimpleQueue queue;
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

void cutRope() {
    CutRope cut_rope;
    cout << cut_rope.cutRope(15) << endl;
}

void minCost() {
    MinCost min_cost;
    string str = "aaabbbabbbb";

    vector<int> cost = {3, 5, 10, 7, 5, 3, 5, 5, 4, 8, 1};
    cout << min_cost.minCost(str, cost) << endl;
}

void minSetSize() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    MinSetSize min_set_size;
    cout << min_set_size.minSetSize(arr) << endl;
    cout << pow(2, 3);
}

void regExMatch() {
    RegExMatch reg_ex_match;
    cout << reg_ex_match.match("ab", ".*c");
}

void lexicalOrder() {
    LexicalOrder lexical_order;
    vector<int> res = lexical_order.lexicalOrder(13);
    for (int i:res) {
        cout << i << endl;
    }
}

void maxPathSum() {
    TreeNode *left = new TreeNode(-1);
    TreeNode *right = new TreeNode(3);
    TreeNode *root = new TreeNode(-2, left, nullptr);

    MaxPathSum max_path_sum;
    cout << max_path_sum.maxPathSum(root);
}


void minStack() {
    MinStack min_stack;
    min_stack.push(1);
    min_stack.push(2);
    min_stack.push(3);
    cout << min_stack.getMin() << endl;
    min_stack.push(4);
    min_stack.push(5);
    min_stack.push(6);
    min_stack.push(7);
    min_stack.push(8);
    cout << min_stack.top() << endl;
    min_stack.push(9);
}


void findKth() {
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    FindKth find_kth;
    cout << find_kth.findKthLargest(nums, 4);
}

void medianFinder() {
    MedianFinder median_finder;
    median_finder.addNum(1);
    median_finder.addNum(2);
    median_finder.addNum(3);
    cout << median_finder.findMedian();
}

void checkSubArray() {
    CheckSubarraySum check_subarray_sum;
    vector<int> nums{23, 2, 4, 6, 7};
    cout << check_subarray_sum.checkSubarraySum(nums, -6);
}

void numberOf1() {
    NumberOf1 number_of_1;
    cout << number_of_1.NumberOf1Between1AndN_Solution(100);
};

void inversePairs() {
    InversePairsCount inverse_pairs_count;
    cout << inverse_pairs_count.InversePairs({1, 2, 3, 4, 5, 6, 7, 0});
}

void KInversePairs() {
    class KInversePairs k_inverse_pairs;
    cout << k_inverse_pairs.kInversePairs(1000, 1000);
}

void GetNumberOfK() {
    GetNumberOfKInSorted get_number_of_k_in_sorted;
    cout << get_number_of_k_in_sorted.GetNumberOfK({1, 2, 2, 3, 3, 3, 4, 5}, 6);
}

void FirstMissingPositive() {
    class FirstMissingPositive first_missing_positive;
    vector<int> nums{3, 4, -1, 1};
    cout << first_missing_positive.firstMissingPositive(nums);
}

void CombinationSum3() {
    class CombinationSum3 combination_sum_3;
    auto res = combination_sum_3.combinationSum3(9, 45);
    for (const auto &nums : res) {
        for (int num: nums) {
            cout << num << " ";
        }
        cout << endl;
    }
}

void MaxSlidingWindow() {
    class MaxSlidingWindow max_sliding_window;
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> res = max_sliding_window.maxSlidingWindow(nums, 3);
    for (int i :res)
        cout << i << " ";
}

void MinWindow() {
    class MinWindow min_window;
    cout << min_window.minWindow("ADOBECODEBANC", "ABC");
}

void MinOperations() {
    class MinOperations min_operations;
//    vector<int> nums1{1,2,3,4,5,6}, nums2{1,1,2,2,2,2};
    vector<int> nums1{1, 1, 1, 1, 1, 1, 1}, nums2{6};
//    vector<int> nums1{5,6,4,3,1,2}, nums2{6,3,3,1,4,5,3,4,1,3,4};

    cout << min_operations.minOperations(nums1, nums2);
}

void LowestCommonAncestor() {
    class LowestCommonAncestor lowest_common_ancestor;
    TreeNode *left = new TreeNode(5);
    TreeNode *right = new TreeNode(1);
    TreeNode *root = new TreeNode(3, left, right);
    lowest_common_ancestor.lowestCommonAncestor(root, left, right);
}

void MaxProfit() {
    class MaxProfit max_profit;
    vector<int> nums{3, 2, 6, 5, 0, 3};
    cout << max_profit.maxProfit(2, nums);
}

void IPToInt() {
    class IPToInt ip_to_int;
    cout << ip_to_int.covert("11.1.1");
}

void ThreeSumClosest() {
    class ThreeSumClosest three_sum_closest;
    vector<int> nums = {-55, -24, -18, -11, -7, -3, 4, 5, 6, 9, 11, 23, 33};
    cout << three_sum_closest.threeSumClosest(nums, 0);
}

void ReorderList() {
    class ReorderList reorder_list;
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    reorder_list.reorderList(&l1);
    ListNode *l = &l1;
    while (l) {
        cout << l->val << endl;
        l = l->next;
    }
}

void Search() {
    class Search search;
    vector<int> nums{2, 5, 6, 0, 0, 1, 2};
    cout << search.search(nums, 0);
}

void NextPermutation() {
    class NextPermutation next_permutation;
    vector<int> nums{1, 3, 2};

    next_permutation.nextPermutation(nums);
    for (int i: nums)
        cout << i << endl;
}


int main() {
    string str;
    cin>>str;
    cout << "str: "<< str <<endl;

    int a;
    cin >> a;
    cout << "a: "<< a <<endl;

    int b;
    cin >> b;
    cout << "b: "<< b <<endl;
}