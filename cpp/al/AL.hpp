//
// Created by shiwk on 2021/3/14.
//

#ifndef CPP_AL_HPP
#define CPP_AL_HPP

#include <unordered_map>
#include <queue>
#include <vector>
#include <set>
#include <numeric>
//#include <cmath>
using namespace std;

class MinSetSize {
public:
    int minSetSize(vector<int> &arr) {
        vector<int> cout_arr;
        unordered_map<int, int> index;
        for (int i : arr) {
            if (index.find(i) == index.end()) {
                index[i] = cout_arr.size();
                cout_arr.push_back(1);
            } else
                cout_arr[index[i]] += 1;
        }

        sort(cout_arr.begin(), cout_arr.end(), greater<int>());

        int res = 0;
        int sum = 0;
        for (int i : cout_arr) {
            res += 1;
            sum += i;
            if (sum >= arr.size() / 2)
                return res;
        }

        return -1;
    }
};

class RegExMatch {
public:
    bool match(string str, string pattern) {
        if (str.empty() && pattern.empty())
            return true;
        return match(str, pattern, 0, 0);
    }

    bool match(string &str, string &pattern, int i, int j) {
        if (i == str.size() && j == pattern.size()) {
            return true;
        }

        if (i != str.size() && j >= pattern.size()) {
            return false;
        }

        if (pattern[j] == '*') {
            if (str[i] != str[i - 1] && pattern[j - 1] != '.')
                return false;

            return i < str.size() && (match(str, pattern, i + 1, j + 1) || match(str, pattern, i + 1, j));
        }

        if (j < pattern.size() - 1 && pattern[j + 1] == '*')
            if (match(str, pattern, i, j + 2)
                ||
                (pattern[j] == '.' || pattern[j] == str[i]) && i < str.size() && (match(str, pattern, i + 1, j + 2) ||
                                                                                  match(str, pattern, i + 1, j + 1))
                    )
                return true;

        if (pattern[j] == '.' || pattern[j] == str[i])
            return i < str.size() && match(str, pattern, i + 1, j + 1);
        return false;
    }
};


class LexicalOrder {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        if (n == 0)
            return res;

        for (int i = 1; i <= 9; i++) {
            res.push_back(i);
            if (lexicalOrderRecurive(res, n))
                return res;
        }

        return res;
    }

    bool lexicalOrderRecurive(vector<int> &arr, int n) {
        if (arr.size() == n)
            return true;

        int end = arr[arr.size() - 1];
        for (int i = 0; i <= 9; i++) {
            int k = end * 10 + i;
            if (k > n)
                return false;
            arr.push_back(k);
            if (lexicalOrderRecurive(arr, n))
                return true;
        }

        return false;
    }
};


class MaxPathSum {
public:
    int maxPathSum(TreeNode *root) {
        TreeNode *shortestChildPathNode = longestChildPath(root);
        return longestAsRoot(root, shortestChildPathNode);
    }

    TreeNode *longestChildPath(TreeNode *node) {
        TreeNode *tn = new TreeNode(node->val);

        cout << "node->val:" << node->val << endl;


        int left = 0, right = 0;
        if (node->left != nullptr) {
            tn->left = longestChildPath(node->left);
            left = (tn->left != nullptr ? tn->left->val : 0);
        }

        if (node->right != nullptr) {
            tn->right = longestChildPath(node->right);
            right = (tn->right != nullptr ? tn->right->val : 0);
        }

        if (left > 0 || right > 0)
            tn->val += left > right ? left : right;


        return tn;
    }

    int longestAsRoot(TreeNode *tree1, TreeNode *tree2) {

        int length = tree1->val;


        if (tree1->left == nullptr && tree1->right == nullptr)
            return length;

        if (tree2->left != nullptr && tree2->left->val > 0)
            length += tree2->left->val;
        if (tree2->right != nullptr && tree2->right->val > 0)
            length += tree2->right->val;

        if (tree1->left != nullptr) {
            int left = longestAsRoot(tree1->left, tree2->left);
            length = length > left ? length : left;
        }

        if (tree1->right != nullptr) {
            int right = longestAsRoot(tree1->right, tree2->right);
            length = length > right ? length : right;
        }

        return length;
    }
};

class Link {
public:
    ListNode *EntryNodeOfLoop(ListNode *pHead) {
        if (!pHead)
            return nullptr;
        int len = loopLength(pHead);
        if (!len)
            return nullptr;

        return findLoopEntry(pHead, len);
    }

    ListNode *ReverseList(ListNode *pHead) {

        if (!pHead)
            return nullptr;
        ListNode dummy(-1);
        dummy.next = pHead;
        ListNode *nh = &dummy;
        ListNode *next = pHead;

        while (next) {
            ListNode *tmp = next;
            next = next->next;
            tmp->next = nh;
            nh = tmp;

            if (nh->next == &dummy)
                nh->next = nullptr;
        }

        return nh;
    }

private:
    int loopLength(ListNode *pHead) {
        ListNode *p = pHead, *q = pHead;
        bool loopFound = false;
        int length = 0;
        while (q->next != nullptr) {
            p = p->next;
            q = q->next->next;
            if (loopFound)
                length++;

            if (p != q)
                continue;

            if (!loopFound)
                loopFound = true;
            else
                return length;
        }

        return length;
    }

    ListNode *findLoopEntry(ListNode *pHead, int length) {
        ListNode *p = pHead;
        ListNode *q = pHead;
        while (length > 0) {
            length--;
            q = q->next;
        }

        while (p != q) {
            p = p->next;
            q = q->next;
        }

        return p;
    }
};

class SubTree {
public:
    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (s == nullptr || t == nullptr)
            return false;
        return HasSubtree(s, t);
    }

private:

    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
        if (pRoot1 == nullptr)
            return false;
        if (HasSubtree2(pRoot1, pRoot2))
            return true;
        return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }

    bool HasSubtree2(TreeNode *pRoot1, TreeNode *pRoot2) {
        if (pRoot2 == nullptr && pRoot1 == nullptr)
            return true;

        if (pRoot1 == nullptr || pRoot2 == nullptr)
            return false;

        if (pRoot1->val == pRoot2->val)
            if (HasSubtree2(pRoot1->left, pRoot2->left) && HasSubtree2(pRoot1->right, pRoot2->right))
                return true;


        return false;
    }
};

class SymmetricalTree {
public:
    bool isSymmetrical(TreeNode *pRoot) {
        return findSymmetrical(pRoot->left, pRoot->right);
    }

private:
    bool findSymmetrical(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;

        if (left->val != right->val)
            return false;

        return findSymmetrical(left->left, right->right) && findSymmetrical(left->right, right->left);
    }

};

class Matrix {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int i = 0, j = 0, t = 0;

        vector<int> res;
        while (2 * t < matrix.size() && 2 * t < matrix.front().size()) {
            spiralOrder(matrix, i++, j++, res);
            t++;
        }
        return res;
    }

private:
    void spiralOrder(vector<vector<int>> &matrix, int row, int col, vector<int> &res) {
        int rightCol = matrix.front().size() - 1 - col;
        int bottomRow = matrix.size() - 1 - row;

        res.push_back(matrix[row][col]);

        if (rightCol > col) {
            for (int i = col + 1; i < rightCol; i++)
                res.push_back(matrix[row][i]);

            res.push_back(matrix[row][rightCol]);
        }

        if (bottomRow > row) {
            for (int i = row + 1; i < bottomRow; i++)
                res.push_back(matrix[i][rightCol]);

            res.push_back(matrix[bottomRow][rightCol]);

            if (rightCol > col) {
                for (int i = rightCol - 1; i > col; i--)
                    res.push_back(matrix[bottomRow][i]);

                res.push_back(matrix[bottomRow][col]);
                for (int i = bottomRow - 1; i > row; i--)
                    res.push_back(matrix[i][col]);
            }
        }
    }
};


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() : size_(0), min_size_(0), capacity_(8), bottom_(new int[8]), min_stack_(new int[8]), min_capacity_(8) {
    }

    void push(int val) {
        resize();
        bottom_[size_] = val;
        if (min_size_ == 0)
            min_stack_[min_size_++] = val;
        if (size_ > 0 && val <= getMin())
            min_stack_[min_size_++] = val;
        size_++;
    }

    void pop() {
        if (size_ == 0)
            return;

        resize();
        if (size_ > 0 && top() == getMin())
            min_size_--;

        size_--;
    }

    int top() {
        return bottom_[size_ - 1];
    }

    int getMin() {
        return min_stack_[min_size_ - 1];
    }


private:
    int *bottom_;
    int *min_stack_;
    int size_;
    int min_size_;
    int capacity_;
    int min_capacity_;

    void resize() {
        if (size_ >= capacity_) {
            capacity_ *= 2;
            int *tmp = bottom_;
            bottom_ = new int[capacity_];
            memcpy(bottom_, tmp, size_ * sizeof(int));
            delete tmp;
        } else if (capacity_ > 8 && size_ < capacity_ / 2) {
            capacity_ /= 2;
            int *tmp = bottom_;
            bottom_ = new int[capacity_];
            memcpy(bottom_, tmp, size_ * sizeof(int));
            delete tmp;
        }

        if (min_size_ >= min_capacity_) {
            min_capacity_ *= 2;
            int *tmp = min_stack_;
            min_stack_ = new int[min_capacity_];
            memcpy(min_stack_, tmp, min_size_ * sizeof(int));
            delete tmp;
        } else if (min_capacity_ > 8 && min_size_ < min_capacity_ / 2) {
            min_capacity_ /= 2;
            int *tmp = min_stack_;
            min_stack_ = new int[min_capacity_];
            memcpy(min_stack_, tmp, min_size_ * sizeof(int));
            delete tmp;
        }
    }
};

class StackSequences {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        stack<int> s;
        int i = 0, j = 0;
        while (i < pushed.size()) {
            if (!s.empty() && s.top() == popped[j]) {
                s.pop();
                j++;
                continue;
            }

            s.push(pushed[i++]);
        }

        while (s.top() == popped[j]) {
            s.pop();
            j++;
        }

        return j == pushed.size();
    }
};

class SquenceOfBST {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty())
            return false;

        return VerifySquenceOfBST(sequence, 0, sequence.size() - 1);
    }

private:
    bool VerifySquenceOfBST(vector<int> sequence, int start, int end) {

        if (start + 1 >= end)
            return true;

        int root = sequence[end];

        int left_count = 0;
        bool right_start_found = false;
        for (int i = start; i < end; ++i) {
            if (right_start_found) {
                if (sequence[i] < root)
                    return false;
            } else if (sequence[i] > root) {
                right_start_found = true;
            } else
                left_count++;
        }
        if (!VerifySquenceOfBST(sequence, start, start + left_count - 1))
            return false;
        return !right_start_found || VerifySquenceOfBST(sequence, start + left_count, end - 1);

    }
};

// Definition for a Node.
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class CopyRandomList {
public:
    Node *copyRandomList(Node *head) {
        if (!head)
            return nullptr;
        DuplicateList(head);
        CopyRandom(head);
        return Decouple(head);
    }

private:
    void DuplicateList(Node *head) {
        Node *p = head;
        while (p) {
            Node *copy = new Node(p->val);
            copy->next = p->next;
            p->next = copy;
            p = copy->next;
        }
    }

    void CopyRandom(Node *head) {
        Node *p = head;
        while (p) {
            Node *copy = p->next;
            copy->random = p->random ? p->random->next : nullptr;
            p = copy->next;
        }
    }

    Node *Decouple(Node *head) {
        Node *p = head;
        Node *q = head->next;
        Node *res = q;
        while (p) {
            p->next = q->next;
            q->next = p->next ? p->next->next : nullptr;
            p = p->next;
            q = q->next;
        }

        return res;
    }
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string str;
        if (!root)
            return str;
        queue<TreeNode *> q;
        q.push(root);
        int count = 1;

        while (!q.empty()) {

            TreeNode *top = q.front();
            if (top) {
                str += (to_string(top->val) + '!');
                q.push(top->left);
                q.push(top->right);
            } else {
                str += '#';
            }
            q.pop();
        }


        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.empty())
            return nullptr;

        queue<TreeNode *> q;
        vector<TreeNode *> nodes;
        int start = 0;
        int end = 0;
        while (start < data.length()) {
            q.push(find(data, start, end));
            start = end + 1;
            end = start;
        }

        nodes.push_back(q.front());
        q.pop();
        int i = 0;
        while (!q.empty()) {
            if (nodes[i]) {
                nodes[i]->left = q.front();
                nodes.push_back(q.front());
                q.pop();

                nodes[i]->right = q.front();
                nodes.push_back(q.front());
                q.pop();
            }
            i++;
        }

        return nodes[0];
    }


private:
    TreeNode *find(string &data, int start, int &end) {
        int i = start;
        if (data[i] == '#') {
            end = i;
            return nullptr;
        }

        string str;
        while (i < data.length()) {
            if (data[i] != '!') {
                str += data[i];
                i++;
                continue;
            }
            end = i;
            break;
        }

        return new TreeNode(stoi(str));
    }
};

class FindKth {
public:
    int findKthLargest(vector<int> &nums, int k) {
        findKth(nums, k);
        return nums[k - 1];
    }

private:

    void findKth(vector<int> &nums, int k) {
        int start = 0;
        int end = nums.size() - 1;

        while (true) {
            int t = partition(nums, start, end);
            if (t == k - 1)
                return;
            else if (t < k - 1) {
                start = t + 1;
            } else {
                end = t - 1;
            }
        }
    }

    int partition(vector<int> &nums, int start, int end) {
        if (start >= end)
            return start;
        int i = start + 1;
        int j = end;
        int key = nums[start];
        while (i <= j) {
            while (i <= j && nums[i] > key) {
                i++;
            }
            while (i <= j && nums[j] < key) {
                j--;
            }

            if (j < i)
                break;

            int tmp = nums[i];
            nums[i++] = nums[j];
            nums[j--] = tmp;
        }

        nums[start] = nums[j];
        nums[j] = key;
        return j;
    }

};

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (left.empty() || num <= left.front()) {
            left.push_back(num);
//            cout<< left.front() <<endl;

            push_heap(left.begin(), left.end(), less<int>());
            cout << "left: " << left.front() << endl;
            if (left.size() - right.size() > 1) {
                pop_heap(left.begin(), left.end(), less<int>());
                int leftToRight = left.back();
                left.pop_back();
                right.push_back(leftToRight);
                push_heap(right.begin(), right.end(), greater<int>());
            }
        } else {
            right.push_back(num);
//            cout<< right.front() <<endl;

            push_heap(right.begin(), right.end(), greater<int>());
            cout << "right: " << right.front() << endl;

            if (right.size() - left.size() > 1) {
                pop_heap(right.begin(), right.end(), greater<int>());
                int rightToLeft = right.back();
                right.pop_back();
                left.push_back(rightToLeft);
                push_heap(left.begin(), left.end(), less<int>());
            }
        }
    }

    double findMedian() {
        if (left.size() > right.size()) {
            return left.front();
        }

        if (left.size() < right.size()) {
            return right.front();
        }

        return (double) (left.front() + right.front()) / 2;
    }

private:
    vector<int> left;
    vector<int> right;
};

class CheckSubarraySum {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> mod_map;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (k == 0) {
                if (i > 0 && nums[i] == 0 && nums[i - 1] == 0)
                    return true;
                continue;
            }
            sum += nums[i];
            int mod = sum % k;
            if (mod_map.find(mod) != mod_map.end())
                return true;
            mod_map[mod] = i;
        }

        return false;
    }

};


class NumberOf1 {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int t = 1;
        int i = 0;
        int res = 0;
        while (t <= n) {
            int k = n % (t * 10) / t;
            if (k < 1) {
                t *= 10;
                i++;
                continue;
            } else if (k == 1) {
                res += (n % t) + 1;
            } else
                res += t;

            res += ((t / 10) * i) * k;
            i++;
            t *= 10;
        }

        return res;
    }
};

class LongestSubstring {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;

        int start = 0;
        int length = 0;
        int res = 0;
        unordered_map<char, int> map;
        set<int> se;
        se.insert(1);
        se.erase(1);

        queue<int> qu;
        qu.push(1);
        qu.front();
        qu.pop();

        stack<int> st;
        st.push(1);
        st.top();
        st.pop();

        for (int i = 0; i < s.length(); i++) {
            if (map.find(s[i]) == map.end()) {
                map[s[i]] = i;
                length++;
                res = res > length ? res : length;
                continue;
            }

            int prev_pos = map[s[i]];
            map[s[i]] = i;

            if (prev_pos < start) {
                length++;
                res = res > length ? res : length;
                continue;
            }

            length = i - prev_pos;
            start = prev_pos + 1;
        }

        return res;
    }
};

class SubarraysWithKDistinct {
public:
    int subarraysWithKDistinct(vector<int> &A, int K) {
        return subarraysWithMaximalKDistinct(A, K) - subarraysWithMaximalKDistinct(A, K - 1);
    }

    int subarraysWithMaximalKDistinct(vector<int> &A, int K) {
        if (A.empty())
            return 0;
        unordered_map<int, int> map;

        int left = 0;
        int right = 0;
        int res = 0;
        while (right < A.size()) {
            map[A[right]]++;

            while (map.size() > K) {
                map[A[left]]--;
                if (map[A[left]] == 0)
                    map.erase(A[left]);
                left++;
            }

            res += right - left + 1;
            right++;
        }

        return res;
    }
};

class TotalFruit {
public:
    int totalFruit(vector<int> &tree) {
        unordered_map<int, int> map;
        int left = 0;
        int right = 0;
        int res = 0;
        while (right < tree.size()) {
            map[tree[right]]++;
            while (map.size() > 2) {
                map[tree[left]]--;
                if (map[tree[left]] == 0)
                    map.erase(tree[left]);
                left++;
            }

            res = res > right - left + 1 ? res : right - left + 1;
            right++;
        }

        return res;
    }
};


class Solution {
public:
    bool isUgly(int n) {
        if (n == 0)
            return false;
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
                continue;
            }
            if (n % 3 == 0) {
                n /= 3;
                continue;
            }

            if (n % 5 == 0) {
                n /= 5;
                continue;
            }

            return false;
        }

        return true;
    }

    int nthUglyNumber(int n) {
        vector<int> nums;
        nums.push_back(1);
        vector<int> ptrs;

        int ptr2 = 0;
        int ptr3 = 0;
        int ptr5 = 0;

        while (nums.size() < n) {
            int next2 = 2 * nums[ptr2];
            int next3 = 3 * nums[ptr3];
            int next5 = 5 * nums[ptr5];

            int num = min(min(next2, next3), next5);
            nums.push_back(num);
            while (nums[ptr2] * 2 <= num) {
                ptr2++;
            }

            while (nums[ptr3] * 3 <= num) {
                ptr3++;
            }

            while (nums[ptr5] * 5 <= num) {
                ptr5++;
            }
        }
        return nums.back();
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        vector<int> nums;
        nums.push_back(1);

        int ptr2 = 0;
        int ptr3 = 0;
        int ptr5 = 0;

        while (nums.size() <= n) {
            int next2 = a * nums[ptr2];
            int next3 = b * nums[ptr3];
            int next5 = c * nums[ptr5];

            int num = min(min(next2, next3), next5);
            nums.push_back(num);
            while ((long long) nums[ptr2] * a <= num) {
                ptr2++;
            }

            while ((long long) nums[ptr3] * b <= num) {
                ptr3++;
            }

            while ((long long) nums[ptr5] * c <= num) {
                ptr5++;
            }
        }
        return nums.back();
    }

    int nthSuperUglyNumber(int n, vector<int> &primes) {
        vector<int> nums;
        nums.push_back(1);
        vector<int> ptrs(primes.size(), 0);

        while (nums.size() < n) {
            int next = INT32_MAX;
            for (int i = 0; i < primes.size(); i++) {
                next = min(next, primes[i] * nums[ptrs[i]]);
            }

            nums.push_back(next);

            for (int i = 0; i < primes.size(); i++) {
                while (primes[i] * nums[ptrs[i]] <= next)
                    ptrs[i]++;
            }
        }

        return nums.back();
    }
};

class SingleNumber {
public:
    int singleNumber(vector<int> &nums) {
        int once = 0;
        int twice = 0;

        for (int i : nums) {
            int newOnce = (once & ~i) | (~once & ~twice & i);
            twice = (twice & ~i) | (once & i);
            once = newOnce;
        }

        return once;
    }
};


class InversePairsCount {
public:
    int InversePairs(vector<int> data) {
        if (data.empty())
            return 0;
        return (int) mergeSort(data, 0, data.size() - 1);
    }

    long long mergeSort(vector<int> &data, int start, int end) {
        if (end <= start)
            return 0;

        if (end == start + 1) {
            if (data[end] >= data[start])
                return 0;

            int tmp = data[start];
            data[start] = data[end];
            data[end] = tmp;
            return 1;
        }

        int mid = (start + end) >> 1;
        long long left = mergeSort(data, start, mid);
        long long right = mergeSort(data, mid + 1, end);

        long long res = (left + right) % 1000000007;
        int i = mid, j = end;
        vector<int> copy(end - start + 1);
        int t = end - start;

        while (t >= 0) {
            if (j == mid) {
                //right empty
                copy[t--] = data[i--];
                continue;
            }
            if (i == start - 1) {
                //left empty
                copy[t--] = data[j--];
                continue;
            }
            if (data[i] > data[j]) {
                copy[t--] = data[i--];
                res = (res + (j - mid)) % 1000000007;
                continue;
            }
            copy[t--] = data[j--];
        }

        for (int k = 0; k < copy.size(); ++k) {
            data[start + k] = copy[k];
        }

        return res;
    }
};

class KInversePairs {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> cache(n + 1, vector<int>(k + 1, 0));
        for (int i = 0; i < n + 1; ++i) {
            cache[i][0] = 1;
        }

        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < k + 1; ++j) {
                int res = 0;
                if (k > n * (n - 1) / 2) {
                    break;
                }
                res = (res + cache[i - 1][j]) % 1000000007;
                res = (res + cache[i][j - 1]) % 1000000007;
                res = (res + 1000000007 - ((j >= i) ? cache[i - 1][j - i] : 0)) % 1000000007;
                cache[i][j] = res;
//                cout << i << " " << j<<" " << cache[i][j] << endl;
            }
        }

        return cache[n][k];
    }
};

class GetIntersectionNode {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return nullptr;

        ListNode *p = headA;
        ListNode *q = headB;

        int i = 0, j = 0;
        while (p || q) {
            if (p) {
                i++;
                p = p->next;
            }

            if (q) {
                j++;
                q = q->next;
            }
        }

        ListNode *l = i > j ? headA : headB;
        ListNode *s = i > j ? headB : headA;

        int dis = i > j ? i - j : j - i;
        int t = 0;
        while (t++ < dis) {
            l = l->next;
        }

        while (l != s) {
            if (!l)
                return nullptr;
            l = l->next;
            s = s->next;
        }

        return l;
    }
};


class GetNumberOfKInSorted {
public:
    int GetNumberOfK(vector<int> data, int k) {
        int first = findFirst(data, k);
        if (first < 0)
            return 0;
        int last = findLast(data, k, first);

        return last - first + 1;
    }

//    int binarySearch(vector<int> &data, int k) {
//        int start = 0;
//        int end = data.size() - 1;
//        while (start <= end) {
//            int mid = (start + end) >> 1;
//            int slot = data[mid];
//            if (slot < k) {
//                start = mid + 1;
//            } else if (slot > k) {
//                end = mid - 1;
//            } else
//                return findLast(data, k, slot) - findFirst(data, k, slot) + 1;
//        }
//
//        return 0;
//    }

    int findFirst(vector<int> &data, int k) {
        int start = 0;
        int end = data.size() - 1;
        while (start <= end) {
            int mid = (start + end) >> 1;
            int slot = data[mid];
            if (slot < k) {
                start = mid + 1;
            } else if (slot >= k) {
                end = mid - 1;
            }

            if (start >= data.size() || data[start] != k)
                return -1;
            return start;
        }
    }

    int findLast(vector<int> &data, int k, int start) {
        int end = data.size() - 1;
        while (start <= end) {
            int mid = (start + end) >> 1;
            int slot = data[mid];
            if (slot > k) {
                end = mid - 1;
            } else if (slot <= k) {
                start = mid + 1;
            }
        }
        return end;
    }
};

class MissingNumber {
public:
    int missingNumber(vector<int> &nums) {
        int res = 0;
        for (int i = 0; i <= nums.size(); ++i) {
            res += i;
        }
        for (int n :nums) {
            res -= n;
        }

        return res;
    }
};

class FirstMissingPositive {
public:
    int firstMissingPositive(vector<int> &nums) {
        for (int i = 0; i < nums.size();) {
            int num = nums[i];
            if (num <= 0 || num > nums.size() || num == i + 1) {
                ++i;
                continue;
            }

            if (nums[num - 1] == num) {
                ++i;
                continue;
            }
            nums[i] = nums[num - 1];
            nums[num - 1] = num;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return nums.size() + 1;
    }
};

class CombinationSum3 {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return combinationSum3(k, n, 9);
    }

    vector<vector<int>> combinationSum3(int k, int n, int max) {
        vector<vector<int>> res;
        if (k < 0 || k > max || n < k * (k + 1) / 2 || n > k * (max + max - k + 1) / 2)
            return res;

        if (k == 1) {
            if (n <= max)
                res.push_back({n});
            return res;
        }

        for (int i = max; i >= k; --i) {
            vector<vector<int>> pre = combinationSum3(k - 1, n - i, i - 1);
            if (pre.empty())
                continue;;
            for (vector<int> pre_res: pre) {
                pre_res.push_back(i);
                res.push_back(pre_res);
            }
        }

        return res;
    }


    vector<vector<int>> combinationSum(vector<int> &candidates, int target, int index) {
        vector<vector<int>> res;
        if (target < 0)
            return res;

        if (target == 0) {
            res.emplace_back();
            return res;
        }

        for (int i = index; i < candidates.size(); i++) {
            int c = candidates[i];
            auto pre = combinationSum(candidates, target - c, i);
            for (auto r : pre) {
                r.push_back(c);
                res.push_back(r);
            }
        }

        return res;
    }
};

class ReverseWords {
public:
    string reverseWords(string s) {
        string res;
        int i = s.length() - 1;
        while (i >= 0) {
            if (s[i] == ' ') {
                i--;
                continue;
            }

            int length = 0;
            int j = i;
            while (j >= 0 && s[j] != ' ') {
                length++;
                j--;
            }

            string word = s.substr(j + 1, length);
            if (!res.empty())
                res += ' ';
            res += word;

            i = j;
        }

        return res;
    }
};

class MaxSlidingWindow {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                if (dq.front() == i - k)
                    dq.pop_front();
            }

            int t = nums[i];
            while (!dq.empty() && t > nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }

        return res;
    }
};

class MinWindow {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;
        unordered_map<char, int> count;

        for (char c:t) {
            map[c]++;
        }

        int p = 0;
        int found = 0;
        string res = s;
        int start = 0;
        while (p < s.length()) {
            if (map.find(s[p]) == map.end()) {
                p++;
                continue;
            }

            count[s[p]]++;
            if (count[s[p]] == map[s[p]])
                found++;

            while (start <= p) {
                if (map.find(s[start]) == map.end()) {
                    start++;
                    continue;
                }
                if (count[s[start]] <= map[s[start]])
                    break;
                count[s[start]]--;
                start++;
            }

            if (found >= map.size() && p - start + 1 < res.length())
                res = s.substr(start, p - start + 1);
            p++;
        }

        return found == map.size() ? res : "";
    }
};

class NumRollsToTarget {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> cache(d + 1, vector<int>(target + 1));
        int m = 1000000007;
        for (int i = 1; i < d + 1; i++) {
            for (int j = 1; j < target + 1; ++j) {
                if (i == 1) {
                    cache[i][j] = j <= f ? 1 : 0;
                    continue;
                }

                for (int k = 1; k <= min(j, f); ++k) {
                    cache[i][j] += cache[i - 1][j - k];
                    cache[i][j] = (m + cache[i][j]) % m;
                }
            }
        }

        return cache[d][target];
    }
};

class MinOperations {
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

        vector<int> bm1(7);
        vector<int> bm2(7);
        for (int i : nums1) {
            bm1[i]++;
        }

        for (int i : nums2) {
            bm2[i]++;
        }
        int r = 0;

        while (sum1 != sum2) {
            int dis = abs(sum1 - sum2) > 5 ? 5 : abs(sum1 - sum2);
            int increasing_chance = sum1 > sum2 ? findIncreasing(bm2) : findIncreasing(bm1);
            int decreasing_chance = sum2 > sum1 ? findDecreasing(bm2) : findDecreasing(bm1);

            if (increasing_chance == -1 && decreasing_chance == -1)
                return -1;

            r++;
            int increasing_dis = min(6, increasing_chance + dis) - increasing_chance;
            int decreasing_dis = decreasing_chance - max(1, decreasing_chance - dis);
            if (decreasing_chance == -1 || increasing_chance != -1 && increasing_dis > decreasing_dis) {
                if (sum1 < sum2) {
                    bm1[increasing_chance]--;
                    bm1[increasing_chance + increasing_dis]++;
                    sum1 += increasing_dis;
                } else {
                    bm2[increasing_chance]--;
                    bm2[increasing_chance + increasing_dis]++;
                    sum2 += increasing_dis;
                }
            } else {
                if (sum1 < sum2) {
                    bm2[decreasing_chance]--;
                    bm2[decreasing_chance - decreasing_dis]++;
                    sum2 -= decreasing_dis;
                } else {
                    bm1[decreasing_chance]--;
                    bm1[decreasing_chance - decreasing_dis]++;
                    sum1 -= decreasing_dis;
                }
            }
        }

        return r;
    }

    int findIncreasing(vector<int> &bm) {
        auto it = find_if(bm.begin(), bm.end() - 1, [=](int i) { return i > 0; });
        return it != bm.end() - 1 ? it - bm.begin() : -1;
    }

    int findDecreasing(vector<int> &bm) {
        for (int i = bm.size() - 1; i > 1; i--) {
            if (bm[i] > 0)
                return i;
        }

        return -1;
    }
};

class LowestCommonAncestor {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        bool foundP = false;
        bool foundQ = false;
        TreeNode *ancestor = findTwo(root, p, q, foundP, foundQ);
        return ancestor;
    }

    TreeNode *findTwo(TreeNode *root, TreeNode *p, TreeNode *q, bool &foundP, bool &foundQ) {
        if (!root)
            return nullptr;

        bool foundP1 = false;
        bool foundQ1 = false;
        TreeNode *left = findTwo(root->left, p, q, foundP1, foundQ1);
        if (left)
            return left;

        bool foundP2 = false;
        bool foundQ2 = false;
        TreeNode *right = findTwo(root->right, p, q, foundP2, foundQ2);
        if (right)
            return right;

        if (foundP1 && foundQ2 || foundQ1 && foundP2) {
            return root;
        }

        foundP = p == root || foundP1 || foundP2;
        foundQ = q == root || foundQ1 || foundQ2;

        return (foundP && foundQ) ? root : nullptr;
    }
};

class ShortestPathLength {
public:
    struct entry {
        int node;
        int cover;
        int length;
    };

    int shortestPathLength(vector<vector<int>> &graph) {
        queue<entry> q;
        vector<vector<int>> m((1 << graph.size()), vector<int>(graph.size(), INT32_MAX));
        for (int i = 0; i < graph.size(); ++i) {
            q.push(entry{i, 1 << i, 0});
            m[1 << i][i] = 0;
        }

        while (!q.empty()) {
            entry e = q.front();
            if (e.cover == (1 << graph.size()) - 1)
                return e.length;
            for (int i : graph[e.node]) {
                int cover = e.cover | 1 << i;
                if (m[cover][i] <= e.length + 1)
                    continue;
                m[cover][i] = e.length + 1;
                entry nei{i, cover, e.length + 1};
                q.push(nei);
            }
            q.pop();
        }

        return -1;
    }
};

class MaxProfit {
public:
//    int maxProfit(vector<int>& prices) {
//        int min = INT32_MAX;
//        int res = 0;
//        for(int p :prices)
//        {
//            res = res == 0 && p < min ? 0 : (p - min) > res ? (p - min): res;
//            min = p <min? p : min;
//        }
//        return res;
//    }

//    int maxProfit(vector<int> &prices) {
//        int cost = 0;
//        int res = 0;
//        for (int i = 0; i < prices.size(); ++i) {
//            if (i == prices.size() - 1) {
//                if (res >0)
//                    res += prices[i] - cost;
//                return res;
//            }
//
//            if (prices[i] < prices[i + 1]) {
//                if (cost == 0)
//                    cost = prices[i];
//                continue;
//            }
//
//            if (prices[i] > prices[i + 1]) {
//                if (cost > 0) {
//                    cost = 0;
//                    res += prices[i] - cost;
//                }
//                continue;
//            }
//        }
//        return res;
//    }

    int maxProfit(vector<int> &prices) {
        int min = INT32_MAX;
        int max = 0;
        int leftMax = 0;
        vector<int> leftProfits(prices.size());
        vector<int> rightProfits(prices.size());
        int rightMax = 0;
        for (int i = 0; i < prices.size(); ++i) {
            int left = prices[i] - min;
            min = min < prices[i] ? min : prices[i];
            leftMax = leftMax > left ? leftMax : left;
            leftProfits[i] = leftMax;

            int r = prices[prices.size() - 1 - i];
            int right = max - r;
            max = max > r ? max : r;
            rightMax = rightMax > right ? rightMax : right;
            rightProfits[prices.size() - 1 - i] = rightMax;
        }

        int res = 0;
        for (int i = 0; i < prices.size(); ++i) {
            int tmp = leftProfits[i] + (i < prices.size() - 1 ? rightProfits[i + 1] : 0);
            res = res > tmp ? res : tmp;
        }

        return res;
    }

    int maxProfit(int k, vector<int> &prices) {
        int res = 0;
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(k + 1, vector<int>(2)));
        for (int i = 0; i < prices.size(); ++i) {
            for (int j = 0; j <= min(i / 2 + 1, k); ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = 0 - prices[i];
                    continue;
                }

                if (j > min((i - 1) / 2 + 1, k))
                    dp[i][j][1] = dp[i - 1][j - 1][0] - prices[i];
                else {
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);

                    res = res > dp[i][j][0] ? res : dp[i][j][0];
                }
            }
        }

        return res;
    }

};

class IPToInt {
public:
    int covert(char *ip) {
        int length = 0;
        while (ip[length] != '\0') { length++; }

        int dotCount = 0;
        int tmpNumber = 0;
        int tmpDcim = 0;
        int res = 0;
        for (int i = length - 1; i >= 0; i--) {
            if (ip[i] == '.') {
                if (tmpNumber == 0)
                    return -1; // 123..255...
                if (dotCount >= 3)
                    return -1; // 123.123.123.123.123
                res += tmpDcim * pow(256, dotCount);
                dotCount++;
                tmpNumber = 0;
                tmpDcim = 0;
            } else if (ip[i] < '0' || ip[i] > '9') {
                return -1; // abc.***...
            }

            if (tmpNumber >= 3)
                return -1;

            tmpDcim = (ip[i] - '0') * pow(10, tmpNumber) + tmpDcim;
            if (tmpDcim >= 256)
                return -1; // 789.***...

            tmpNumber++;
        }

        if (dotCount > 3)
            return -1; // 123.123.123.123.123
        return res;
    }
};

class ThreeSum {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;
        sort(nums.begin(), nums.end());
        int first = 0;
        while (first < nums.size() - 2) {
            if (first > 0 && nums[first] == nums[first - 1]) {
                first++;
                continue;
            }

            int second = first + 1;
            int third = nums.size() - 1;

            while (second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                if (sum == 0) {
                    res.push_back({nums[first], nums[second], nums[third]});
                }
                if (sum >= 0) {
                    third--;
                    while (second < third && nums[third] == nums[third + 1])
                        third--;
                }
                if (sum <= 0) {
                    second++;
                    while (second < third && nums[second] == nums[second - 1])
                        second++;
                }
            }

            first++;
        }

        return res;

    }
};

class ThreeSumClosest {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int absDiff = INT32_MAX;
        sort(nums.begin(), nums.end());

        int res = 0;
        int first = 0;
        while (first < nums.size() - 2) {
            if (first > 0 && nums[first] == nums[first - 1]) {
                first++;
                continue;
            }

            int second = first + 1;
            int third = nums.size() - 1;
            while (second < third) {
                int r = nums[first] + nums[second] + nums[third];
                int absR = abs(r - target);
                if (absR < absDiff) {
                    absDiff = absR;
                    res = r;
                }

                if (r == target)
                    return target;


                if (r < target) {
                    second++;
                    while (second < third && nums[second] == nums[second - 1])
                        second++;
                }
                if (r > target) {
                    third--;
                    while (second < third && nums[third] == nums[third + 1])
                        third--;
                }
            }

            first++;
        }

        return res;
    }
};

class ReorderList {
public:
    void reorderList(ListNode *head) {
        deque<ListNode *> dq;
        ListNode *p = head;
        while (p) {
            dq.push_back(p);
            p = p->next;
        }

        ListNode dummy(0);
        ListNode *q = &dummy;
        bool front = true;
        while (!dq.empty()) {
            q->next = front ? dq.front() : dq.back();
            q = q->next;
            if (front)
                dq.pop_front();
            else
                dq.pop_back();
            front = !front;
        }
        q->next = nullptr;
    }
};


class MinDistance {
public:
    int minDistance(string word1, string word2) {
        int length1 = word1.length();
        int length2 = word2.length();

        vector<vector<int>> arr(length1 + 1, vector<int>(length2 + 1));

        for (int i = 0; i <= length1; ++i) {
            for (int j = 0; j <= length2; ++j) {
                if (i == 0 || j == 0) {
                    arr[i][j] = i | j;
                    continue;
                }
                if (word1[i - 1] == word2[j - 1])
                    arr[i][j] = arr[i - 1][j - 1];
                else
                    arr[i][j] = min(arr[i][j - 1], min(arr[i - 1][j], arr[i - 1][j - 1])) + 1;
            }
        }

        return arr[length1][length2];
    }
};

class DetectCycle {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head, *q = head;
        while (p && p->next) {
            p = p->next->next;
            q = q->next;

            if (p == q)
                break;
        }

        if (!p || !p->next)
            return nullptr;

        int circleLength = 0;
        do {
            circleLength++;
            p = p->next->next;
            q = q->next;
        } while (p != q);

        p = head, q = head;
        int i = 0;
        while (i++ < circleLength) {
            p = p->next;
        }

        while (p != q) {
            p = p->next;
            q = q->next;
        }

        return p;
    }
};


class LengthOfLIS {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty())
            return 0;

        vector<int> lengthArr(nums.size(), 1);
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    lengthArr[i] = max(lengthArr[i], lengthArr[j] + 1);
                }
            }
            res = max(lengthArr[i], res);
        }

        return res;
    }
};

class IncreasingTriplet {
public:
    bool increasingTriplet(vector<int> &nums) {
        int minFirst = INT32_MAX;
        int minSecond = INT32_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > minSecond)
                return true;
            minFirst = min(minFirst, nums[i]);
            minSecond = nums[i] > minFirst && nums[i] < minSecond ? nums[i] : minSecond;
        }

        return false;
    }
};

struct item {
    int id;
    int val;
    int count;

    bool operator<(const item &i) const {
        return count < i.count || count == i.count && id < i.id;
    }
};

class FreqStack {
public:
    FreqStack() {
        push_times_ = 0;
    }

    void push(int val) {
        q_.push({++push_times_, val, ++count_[val]});
    }

    int pop() {
        int r = q_.top().val;
        q_.pop();
        count_[r]--;
        return r;
    }

private:
    int push_times_;
    unordered_map<int, int> count_;
    priority_queue<item, vector<item>, std::less<item>> q_;
};


class Subsets {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<vector<int>> index;

        index.emplace_back(vector<int>{-1});
        res.emplace_back(vector<int>{});
        int i = 0;
        while (i < index.size()) {
            for (int j = index[i].back() + 1; j < nums.size(); j++) {
                vector<int> cur = res[i];
                cur.push_back(nums[j]);
                res.push_back({cur});

                vector<int> cur_index = index[i];
                cur_index.push_back(j);
                index.push_back(cur_index);
            }

            if (index[i].back() >= nums.size() - 1) {
                i++;
                continue;
            }

            i++;
        }

        return res;
    }
};

class Search {
public:
//    int search(vector<int> &nums, int target) {
//        int start = 0;
//        int end = nums.size() - 1;
//
//        while (start <= end) {
//            int mid = (start + end) >> 1;
//            if (nums[mid] >= nums[0]) {
//                start = mid + 1;
//                continue;
//            } else if (nums[mid] < nums[0]) {
//                end = mid - 1;
//                continue;
//            }
//        }
//        int firstDecreasing = end;
//        if (target > nums[0])
//            return binarySearch(nums, target, 0, end);
//        else if (target < nums[0])
//            return binarySearch(nums, target, end + 1, nums.size() - 1);
//        return 0;
//    }

    bool search(vector<int> &nums, int target) {
        int start = 0, end = nums.size() - 1;

        while (start <= end) {
            int mid = (start + end) >> 1;
            if (nums[mid] >= nums[0]) {
                start = mid + 1;
                continue;
            } else if (nums[mid] < nums[0]) {
                end = mid - 1;
                continue;
            }
        }
        if (end == nums.size() - 1 && nums[end] == nums[0]) {
            start = 0, end = nums.size() - 1;

            while (start <= end) {
                int mid = (start + end) >> 1;
                if (nums[mid] > nums[0]) {
                    start = mid + 1;
                    continue;
                } else if (nums[mid] <= nums[0]) {
                    end = mid - 1;
                    continue;
                }
            }
        }

        if (end == -1)
            return target == nums[0];
        int firstDecreasing = end;

        if (target > nums[0])
            return binarySearch(nums, target, 0, firstDecreasing) >= 0;
        else if (target < nums[0])
            return binarySearch(nums, target, firstDecreasing + 1, nums.size() - 1) >= 0;
        return true;
    }

    int binarySearch(vector<int> &nums, int target, int start, int end) {
        if (start >= nums.size() || end <= 0)
            return -1;

        while (start <= end) {
            int mid = (start + end) >> 1;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target) {
                end = mid - 1;
                continue;
            }
            if (nums[mid] < target) {
                start = mid + 1;
                continue;
            }
        }
        return -1;
    }
};

class LongestValidParentheses {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int dp[s.length()];
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                dp[i] = 0;
            else {
                if (i == 0)
                    dp[i] = 0;
                else {
                    int matched = i - dp[i - 1] - 1;
                    if (matched < 0 || s[matched] == ')')
                        dp[i] = 0;
                    else if (matched == 0 || s[matched - 1] == '(')
                        dp[i] = dp[i - 1] + 2;
                    else
                        dp[i] = dp[matched - 1] + dp[i - 1] + 2;
                }
            }

            res = max(res, dp[i]);
        }

        return res;
    }
};

class NextPermutation {
public:

    void nextPermutation(vector<int> &nums) {
        int i = nums.size() - 2;
        for (; i >= 0; --i) {
            if (nums[i] < nums[i + 1])
                break;
        }

        int re_start = 0;
        if (i != -1) {
            int key = nums[i];
            int s = i + 1;
            int e = nums.size() - 1;
            while (s <= e) {
                int mid = (s + e) >> 1;
                if (nums[mid] <= key) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }

            swap(nums[i], nums[e]);
            re_start = e;
        }

        std::reverse(nums.begin() + i + 1, nums.end());
    }
};

class NumIslands {
public:
    int numIslands(vector<vector<char>> &grid) {
        unordered_map<int, bool> visited;
        int row = grid.size();
        int col = grid.front().size();
        int res = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1' && visited.find(i * col + j) == visited.end()) {
                    res++;
                    int index = i * col + j;
                    visited[index] = true;

                    queue<int> q;
                    q.push(index);
                    while (!q.empty()) {
                        int f = q.front();
                        int r = f / col;
                        int c = f % col;
                        if (isNotVisted(r, c - 1, row, col, visited)) {
                            int left = f - 1;
                            visited[left] = true;
                            if (grid[r][c - 1] == '1')
                                q.push(left);
                        }
                        if (isNotVisted(r, c + 1, row, col, visited)) {
                            int right = f + 1;
                            visited[right] = true;
                            if (grid[r][c + 1] == '1')
                                q.push(right);
                        }
                        if (isNotVisted(r - 1, c, row, col, visited)) {
                            int up = f - col;
                            visited[up] = true;
                            if (grid[r - 1][c] == '1')
                                q.push(up);
                        }
                        if (isNotVisted(r + 1, c, row, col, visited)) {
                            int down = f + col;
                            visited[down] = true;
                            if (grid[r + 1][c] == '1')
                                q.push(down);
                        }
                        q.pop();
                    }
                }
            }
        }
        return res;
    }

    bool isNotVisted(int r, int c, int row, int col, unordered_map<int, bool> &m) {
        return r >= 0 && r < row && c >= 0 && c < col && m.find(r * col + c) == m.end();
    }
};

class ReverseBetween {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *p = head;
        ListNode *next = head ->next;

        int i = 1;
        while (i != left)
        {
            i++;
            pre = p;
            p = next;
            next = next->next;
        }

        ListNode *oldLeft = p, *tmpLeft = p;
        while (i <= right){
            p -> next = tmpLeft;
            tmpLeft = p;
            p = next;
            next = next ? next ->next : nullptr;
            i++;
        }

        oldLeft->next = p;
        pre->next = tmpLeft;

        return dummy.next;
    }
};


class MaximumSwap {
public:
    int maximumSwap(int num) {
        if (num <= 10)
            return num;
        vector<int> nums;
        while (num != 0)
        {
            nums.push_back(num % 10);
            num/=10;
        }

        std::reverse(nums.begin(), nums.end());
        int found = -1;
        int toBeRpelaced = -1;
        for (int i = 1; i < nums.size(); ++i) {
            int n = nums[i];
            if (n < nums[i-1]) {
                continue;
            }

            if (found > 0 && n < nums[found])
            {
                continue;
            }
            int j = toBeRpelaced >= 0 ? toBeRpelaced : i - 1;
            for (; j >=0 ; --j) {
                if (n <= nums[j])
                    break;
            }

            if (nums[j+1] < nums[i]) {
                toBeRpelaced = j + 1;
                found = i;
            }
        }
        if (found > 0)
            swap(nums[found], nums[toBeRpelaced]);

        int res =0;
        for (int i = 0; i < nums.size(); ++i) {
            res+= nums[i]*pow(10, nums.size() - 1 - i);
        }

        return res;
    }
};

class FindPeakElement {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int start = 0;
        int end = nums.size() - 1;

        while (true){
            int mid = (start +end) >> 1;
            bool greaterThanLeft = mid == 0 || nums[mid] > nums[mid - 1];
            bool greaterThanRight = mid == nums.size() || nums[mid] > nums[mid + 1];
            if (greaterThanLeft && greaterThanRight)
                return mid;

            if (!greaterThanLeft)
                end = mid - 1;

            if (!greaterThanRight)
                start = mid +1;
        }
        return -1;
    }
};

class Rand10 {
public:
    int rand10() {
        while (true)
        {
            int t = rand7();
            int d = 8;
            while (d > 5)
                d = rand7();
            int start = 0;
            if (t < 4)
                return 1 + d % 5;
            else if (t >4)
                return 6 + d % 5;
            else
                continue;
        }
        return 0;
    }

    int rand7();
};

#endif //CPP_AL_HPP
