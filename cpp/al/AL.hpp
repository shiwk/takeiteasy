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
#include <unordered_set>
#include <stack>

using namespace std;

class MinSetSize {
public:
    int minSetSize(vector<int> &arr) {
        vector<int> cout_arr;
        unordered_map<int, int> index;
        for (int i: arr) {
            if (index.find(i) == index.end()) {
                index[i] = cout_arr.size();
                cout_arr.push_back(1);
            } else
                cout_arr[index[i]] += 1;
        }

        sort(cout_arr.begin(), cout_arr.end(), greater<int>());

        int res = 0;
        int sum = 0;
        for (int i: cout_arr) {
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

// 二叉树最大路径和
class MaxPathSum {
public:
    int maxPathSum(TreeNode *root) {
        int res = INT32_MIN;
        maxPathSum(root, res);
        return res;
    }

    int maxPathSum(TreeNode *root, int &res) {
        if (!root)
            return 0;

        int left = maxPathSum(root->left, res);
        int right = maxPathSum(root->right, res);

        int rootRes = root->val + (left > 0 ? left : 0) + (right > 0 ? right : 0);
        res = max(rootRes, res);

        int leafPath = (left > right) ? left : right;
        return root->val + (leafPath > 0 ? leafPath : 0);
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

    //反转链表
    ListNode *ReverseList(ListNode *pHead) {

        ListNode *prev = nullptr;
        ListNode *p = pHead;
        while (p) {
            ListNode *next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }

        return p;
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

//螺旋矩阵,蛇形打印
class SpiralOrder {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        spiralOrder(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1, res);
        return res;
    }

    void spiralOrder(vector<vector<int>> &matrix, int r, int c, int m, int n, vector<int> &nums) {
        if (r > m || c > n)
            return;
        int i = r, j = c;
        while (r <= i && i <= m && c <= j && j <= n) {
            nums.push_back(matrix[i][j]);
            if (j == n) {
                i++;
                break;
            }
            j++;
        }


        while (r <= i && i <= m && c <= j && j <= n) {
            nums.push_back(matrix[i][j]);
            if (i == m) {
                j--;
                break;
            }
            i++;
        }

        while (r <= i && i <= m && c <= j && j <= n) {
            nums.push_back(matrix[i][j]);
            if (j == c) {
                i--;
                break;
            }
            j--;
        }

        while (r <= i && i <= m && c <= j && j <= n) {
            if (i == r) {
                break;
            }
            nums.push_back(matrix[i][j]);
            i--;
        }

        r++;
        c++;
        m--;
        n--;

        spiralOrder(matrix, r, c, m, n, nums);
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
        return findKthLargest(nums, k, 0, nums.size() - 1);
    }

    int findKthLargest(vector<int> &nums, int k, int left, int right) {
        int loc = partition(nums, left, right);

        if (loc == nums.size() - k)
            return nums[loc];

        if (loc > nums.size() - k)
            return findKthLargest(nums, k, left, loc - 1);

        return findKthLargest(nums, k, loc + 1, right);

    }

    int partition(vector<int> &nums, int left, int right) {
        if (left > right)
            return -1;

        int index = rand() % (right - left + 1) + left;
        swap(nums[index], nums[left]);
        index = left;
        int num = nums[index];

        while (left <= right) {
            if (nums[left] <= num) {
                left++;
            }

            if (left <= right && nums[right] >= num) {
                right--;
            }

            if (left < right && nums[left] > num && nums[right] < num) {
                std::swap(nums[left], nums[right]);
            }
        }

        std::swap(nums[right], nums[index]);

        return right;
    }

    int heapMinimal(vector<int> &nums, int k) {
        int i = nums.size() - 1;

        // 小顶堆
        while (i >= 0) {
            int j = i;
            while (j < nums.size()) {
                int left = 2 * j < nums.size() ? nums[2 * j] : INT32_MAX;
                int right = 2 * j + 1 < nums.size() ? nums[2 * j + 1] : INT32_MAX;
                int minChild = min(left, right);
                int minLeaf = left <= right ? 2 * j : 2 * j + 1;

                if (nums[j] < minChild) {
                    swap(nums[j], nums[minLeaf]);
                    j = minLeaf;
                } else
                    break;
            }
            i--;
        }

        // 小顶堆删除n-k 个数字
        int n = 0;
        while (n++ <= nums.size() - k) {
            swap(nums[0], nums[nums.size() - n - 1]);
            int j = 0;
            while (j < nums.size() - n - 1) {
                int left = 2 * j < nums.size() - n - 1 ? nums[2 * j] : INT32_MAX;
                int right = 2 * j + 1 < nums.size() - n - 1 ? nums[2 * j + 1] : INT32_MAX;
                int minChild = min(left, right);
                int minLeaf = left <= right ? 2 * j : 2 * j + 1;


                if (nums[j] < minChild) {
                    swap(nums[j], nums[minLeaf]);
                    j = minLeaf;
                } else
                    break;
            }
        }
        return 0;
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
        int res = 0;
        int length = 0;
        unordered_map<char, int> locs;

        for (int i = 0; i < s.size(); i++) {
            if (locs.find(s[i]) != locs.end())
                length = i - locs[s[i]];
            else {
                length += 1;
            }
            locs[s[i]] = i;
//          locs.emplace(s[i],i);

            res = std::max(length, res);
        }

        return res;
    }

    int lengthOfLongestSubstringV2(string s) {
        int left = 0;
        int right = 0;
        int res = 0;
        unordered_set<char> chs;
        while (right < s.size()) {
            char c = s[right];
            while (chs.find(c) != chs.end()) {
                chs.erase(s[left]);
                left++;
            }
            chs.insert(c);

            res = std::max(res, right - left + 1);
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

        for (int i: nums) {
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
        for (int n: nums) {
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
            for (auto r: pre) {
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

        for (char c: t) {
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
        for (int i: nums1) {
            bm1[i]++;
        }

        for (int i: nums2) {
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

//最近的公共祖先
class LowestCommonAncestor {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root)
            return nullptr;
        if (root == p || root == q) return root;

        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;

        if (!left && !right) return nullptr;

        if (left) return left;
        return right;
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
            for (int i: graph[e.node]) {
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

    int maxProfit2(vector<int> &prices) {
        vector<vector<int>> profits(prices.size(), vector<int>(2));
        profits[0][0] = 0;
        profits[0][1] = -prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            profits[i][0] = std::max(profits[i - 1][0], profits[i - 1][1] + prices[i] - prices[i - 1]);
            profits[i][1] = std::max(profits[i - 1][1], profits[i - 1][0] - prices[i]);
        }

        return profits[prices.size() - 1][0];
    }

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

class Sum {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                i++;
                continue;
            }
            int b = i + 1;
            int c = nums.size() - 1;

            while (b < c) {
                int sum = nums[i] + nums[b] + nums[c];
                if (sum == 0) {
                    res.push_back({nums[i], nums[b], nums[c]});
                }

                if (sum <= 0) {
                    b++;
                    while (b < c && nums[b] == nums[b - 1]) {
                        b++;
                    }
                }

                if (sum >= 0) {
                    c--;
                    while (b < c && nums[c] == nums[c + 1]) {
                        c--;
                    }
                }
            }
        }

        return res;

    }

    vector<int> twoSum(vector<int> nums, int target) {
        vector<int> res;
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); ++i) {
            int dis = target - nums[i];
            if (um.find(dis) != um.end()) {
                res.push_back(um[dis]);
                res.push_back(i);

                return res;
            }

            um[nums[i]] = i;
        }
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


// 重排列表
class ReorderList {
public:
    void reorderList(ListNode *head) {
        ListNode *fast = head, *slow = head;
        ListNode *pre = nullptr;
        while (fast && fast->next) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }

        ListNode *p;
        if (fast) {
            p = slow->next;
            slow->next = nullptr;
        } else {
            p = slow;
            pre->next = nullptr;
        }

        pre = nullptr;

        // reverse second part
        while (p) {
            ListNode *next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }

        ListNode *head1 = head;
        ListNode *head2 = pre;
        ListNode dummy;
        p = &dummy;

        int count = 0;
        while (head1 || head2) {
            if (count++ % 2 == 0) {
                p->next = head1;
                p = p->next;
                head1 = head1->next;
            } else {
                p->next = head2;
                p = p->next;
                head2 = head2->next;
            }
        }
    }
};


// 字符串编辑距离
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

// 环形链表
class DetectCycle {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        int i = 0;
        while (true) {
            if (!fast || !fast->next)
                return nullptr;
            fast = fast->next->next;
            slow = slow->next;

            i++;
            if (fast == slow)
                break;
        }

        ListNode *front = head, *back = head;
        while (i > 0) {
            front = front->next;
            i--;
        }


        while (front != back) {
            front = front->next;
            back = back->next;
        }


        return front;

    }
};

//最长递增子序列
class LengthOfLIS {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> locs;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int loc = findFirstBigger(locs, num);
            if (loc >= locs.size())
                locs.push_back(num);
            else
                locs[loc] = num;
        }

        return locs.size();
    }

    int findFirstBigger(vector<int> nums, int num) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == num)
                return mid;
            if (nums[mid] < num) {
                left = mid + 1;
            } else
                right = mid - 1;
        }

        return left;
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

//搜索旋转排序数组
class Search {
public:
    int search(vector<int> nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) >> 1;
            if (target == nums[mid])
                return mid;

            if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && target < nums[mid])
                    return binarySearch(nums, left, mid - 1, target);
                left = mid + 1;
                continue;
            }

            if (nums[mid] <= nums[right]) {
                if (nums[mid] < target && target <= nums[right])
                    return binarySearch(nums, mid + 1, right, target);
                right = mid - 1;
                continue;
            }

        }
        return -1;

    }

    int binarySearch(vector<int> nums, int left, int right, int target) {
        if (left > right)
            return -1;

        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target) {
                left = mid + 1;
                continue;
            }

            right = mid - 1;
        }

        return -1;
    }
};

class LongestValidParentheses {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        vector<int> len(s.length());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                len[i] = 0;
            if (i == 0)
                continue;
            if (s[i] == ')') {
                if (s[i - 1] == '(')
                    len[i] = (i > 1 ? len[i - 2] : 0) + 2;
                else {
                    int loc = i - 1 - len[i - 1];
                    len[i] = loc < 0 || s[loc] != '(' ? 0 : (loc > 1 ? len[loc - 1] : 0) + len[i - 1] + 2;
                }
            }

            res = max(res, len[i]);
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

//岛屿连接
class NumIslands {
public:
    int numIslands(vector<vector<char>> &grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    res += 1;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>> &grid, int i, int j) {
        grid[i][j] = '0';
        if (i > 0 && grid[i - 1][j] == '1') dfs(grid, i - 1, j);
        if (i < grid.size() - 1 && grid[i + 1][j] == '1') dfs(grid, i + 1, j);
        if (j > 0 && grid[i][j - 1] == '1') dfs(grid, i, j - 1);
        if (j < grid[0].size() - 1 && grid[i][j + 1] == '1')dfs(grid, i, j + 1);
    }


    int numIslandsV2(vector<vector<char>> &grid) {
        int res = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                }
            }
        }
        return res;
    }

    void bfs(vector<vector<char>> &grid, int r, int c) {
        queue<pair<int, int>> q;
        pair<int, int> first(r, c);
        q.push(first);

        while (!q.empty()) {
            auto p = q.front();
            grid[p.first][p.second] = '0';
            q.pop();

            int i = p.first;
            int j = p.second;
            if (i > 0 && grid[i - 1][j] == '1')
                q.push({i - 1, j});
            if (i < grid.size() - 1 && grid[i + 1][j] == '1')
                q.push({i + 1, j});
            if (j > 0 && grid[i][j - 1] == '1')
                q.push({i, j - 1});
            if (j < grid[0].size() - 1 && grid[i][j + 1] == '1')
                q.push({i, j + 1});
        }
    }


};

// 反转链表区间
class ReverseBetween {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode dummy;
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *p = head;
        ListNode *end = head;

        int shift = 1;
        while (shift <= right) {
            if (shift < left) {
                pre = p;
                p = p->next;
            }

            shift++;
            end = end->next;
        }
        ListNode *start = pre;
        pre = end;

        while (p != end) {
            ListNode *next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }

        start->next = pre;

        return dummy.next;
    }
};


class MaximumSwap {
public:
    int maximumSwap(int num) {
        if (num <= 10)
            return num;
        vector<int> nums;
        while (num != 0) {
            nums.push_back(num % 10);
            num /= 10;
        }

        std::reverse(nums.begin(), nums.end());
        int found = -1;
        int toBeRpelaced = -1;
        for (int i = 1; i < nums.size(); ++i) {
            int n = nums[i];
            if (n < nums[i - 1]) {
                continue;
            }

            if (found > 0 && n < nums[found]) {
                continue;
            }
            int j = toBeRpelaced >= 0 ? toBeRpelaced : i - 1;
            for (; j >= 0; --j) {
                if (n <= nums[j])
                    break;
            }

            if (nums[j + 1] < nums[i]) {
                toBeRpelaced = j + 1;
                found = i;
            }
        }
        if (found > 0)
            swap(nums[found], nums[toBeRpelaced]);

        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res += nums[i] * pow(10, nums.size() - 1 - i);
        }

        return res;
    }
};

class FindPeakElement {
public:
    int findPeakElement(vector<int> &nums) {
        if (nums.size() == 1)
            return 0;
        int start = 0;
        int end = nums.size() - 1;

        while (true) {
            int mid = (start + end) >> 1;
            bool greaterThanLeft = mid == 0 || nums[mid] > nums[mid - 1];
            bool greaterThanRight = mid == nums.size() || nums[mid] > nums[mid + 1];
            if (greaterThanLeft && greaterThanRight)
                return mid;

            if (!greaterThanLeft)
                end = mid - 1;

            if (!greaterThanRight)
                start = mid + 1;
        }
        return -1;
    }
};

class Rand10 {
public:
    int rand10() {
        while (true) {
            int t = rand7();
            int d = 8;
            while (d > 5)
                d = rand7();
            int start = 0;
            if (t < 4)
                return 1 + d % 5;
            else if (t > 4)
                return 6 + d % 5;
            else
                continue;
        }
        return 0;
    }

    int rand7();
};

class MaxSubArray {
public:
    int maxSubArray(vector<int> &nums) {
        if (nums.empty())
            return 0;

        int res = nums[0];
        int prev = res;
        for (int i = 1; i < nums.size(); ++i) {
            if (prev < 0)
                prev = nums[i];
            else {
                prev += nums[i];
            }

            res = std::max(res, prev);
        }

        return res;
    }
};

class StringIsValid {
public:
    bool isValid(const string &s) {
        std::stack<char> ss;
        for (const char &i: s) {
            if (i == '(' || i == '{' || i == '[') {
                ss.push(i);
                continue;
            }
            if (ss.empty())
                return false;

            if (i == ')' && ss.top() != '(')
                return false;

            if (i == '}' && ss.top() != '}')
                return false;

            if (i == ']' && ss.top() != ']')
                return false;

            ss.pop();
        }

        return ss.empty();
    }
};

// zigzag 打印树
class ZigZagLevelOrder {
public:
    vector<vector<int>> zigZagLevelOrder(TreeNode *root) {

        stack<TreeNode *> level;
        if (root)
            level.push(root);
        vector<vector<int>> res;
        bool back = false;
        while (!level.empty()) {
            vector<int> levelRes;
            stack<TreeNode *> nextLevel;
            while (!level.empty()) {
                auto front = level.top();
                levelRes.push_back(front->val);

                if (back) {
                    if (front->right)
                        nextLevel.push(front->right);
                    if (front->left)
                        nextLevel.push(front->left);
                } else {
                    if (front->left)
                        nextLevel.push(front->left);
                    if (front->right)
                        nextLevel.push(front->right);
                }

                level.pop();
            }
            level = nextLevel;
            back ^= true;
            res.push_back(levelRes);
        }

        return res;
    }
};

class LevelOrder {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        res.push_back({root->val});
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            vector<TreeNode *> level;
            vector<int> lres;
            while (!q.empty()) {
                auto node = q.front();
                if (node->left)
                    level.push_back(node->left);
                if (node->right)
                    level.push_back(node->right);
                q.pop();
                lres.push_back(node->val);
            }
            res.push_back(lres);

            for (auto node: level) {
                q.push(node);
            }
        }

        return res;
    }
};


struct comp {
    bool operator()(ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

priority_queue<ListNode *, vector<ListNode *>, comp> q;


// 括号生成
class GenerateParenthesis {
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        generateParenthesis(res, str, n, 0, 0);
    }


    void generateParenthesis(vector<string> &res, string &str, int n, int left, int right) {
        if (left == right && left == n) {
            res.emplace_back(str);
            return;
        }

        if (left < n) {
            str.push_back('(');
            generateParenthesis(res, str, n, left + 1, right);
            str.pop_back();
        }

        if (left > right) {
            str.push_back(')');
            generateParenthesis(res, str, n, left, right + 1);
            str.pop_back();
        }
    }
};


class SortArray {
    vector<int> sortArray(vector<int> &nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int> &nums, int left, int right) {
        if (left >= right)
            return;

        int p = partition(nums, left, right);
        if (p >= 0) {
            quickSort(nums, left, p - 1);
            quickSort(nums, p + 1, right);
        }
    }

    int partition(vector<int> &nums, int left, int right) {
        if (left > right)
            return -1;

        int index = rand() % (right - left + 1) + left;
        swap(nums[index], nums[left]);
        index = left;
        int num = nums[index];

        while (left <= right) {
            if (nums[left] <= num)
                left++;

            if (left <= right && nums[right] >= num) {
                right--;
            }

            if (left < right && nums[left] > num && nums[right] < num) {
                swap(nums[left], nums[right]);
            }
        }

        swap(nums[index], nums[right]);

        return right;
    }
};


// 最长回文子串
class LongestPalindrome {
public:
    string longestPalindrome(string s) {
        queue<int> q;
        q.push(0);
        q.push(1);
        int loc = 0;
        int len = 1;

        for (int i = 1; i < s.size(); i++) {
            vector<int> lens;
            while (!q.empty()) {
                int front = q.front();

                if (i - 1 - front >= 0 && s[i] == s[i - 1 - front]) {
                    lens.push_back(front + 2);
                    if (front + 2 > len) {
                        loc = i;
                        len = front + 2;
                    }
                }

                q.pop();
            }

            lens.push_back(0);
            lens.push_back(1);

            for (auto l: lens)
                q.push(l);
        }

        string res = s.substr(loc - len + 1, len);
        return res;
    }
};

// 全排列
class Permute {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<bool> flag(nums.size(), true);
        vector<vector<int>> res;
        vector<int> seq;
        dfs(res, nums, flag, seq);
        return res;
    }

    void dfs(vector<vector<int>> &res, vector<int> &nums, vector<bool> &flag, vector<int> &seq) {
        for (int i = 0; i < nums.size(); i++) {
            if (flag[i]) {
                flag[i] = false;
                seq.push_back(nums[i]);
                dfs(res, nums, flag, seq);
                seq.pop_back();
                flag[i] = true;
            }
        }

        if (seq.size() == nums.size()) {
            res.push_back(seq);
        }
    }
};

// 递增矩阵中第k小
class KthSmallest {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {

        int row = matrix.size();
        int col = matrix[0].size();
        int count = 1;
        while (count < k) {
            int last = row * col - count;
            swap(matrix[0][0], matrix[last / col][last % col]);
            int i = 0, j = 0;
            while (true) {
                cout << i << " " << j << endl;

                bool rightValid = j + 1 < col && i * col + j + 1 < last;
                bool downValid = i + 1 < row && (i + 1) * col + j < last;

                if (!rightValid && !downValid) {
                    break;
                }

                if (!rightValid) {
                    // down
                    if (matrix[i + 1][j] < matrix[i][j]) {
                        swap(matrix[i + 1][j], matrix[i][j]);
                        i = i + 1;
                        continue;
                    } else
                        break;
                } else if (!downValid) {
                    // right
                    if (matrix[i][j + 1] < matrix[i][j]) {
                        swap(matrix[i][j + 1], matrix[i][j]);
                        j = j + 1;
                        continue;
                    } else
                        break;
                } else if (matrix[i + 1][j] <= matrix[i][j + 1]) {
                    if (matrix[i + 1][j] < matrix[i][j]) {
                        swap(matrix[i + 1][j], matrix[i][j]);
                        i = i + 1;
                        continue;
                    } else
                        break;
                } else if (matrix[i + 1][j] > matrix[i][j + 1]) {
                    if (matrix[i][j + 1] < matrix[i][j]) {
                        swap(matrix[i][j + 1], matrix[i][j]);
                        j = j + 1;
                        continue;
                    } else
                        break;
                }
                break;
            }
            count++;
        }

        return matrix[0][0];
    }

};

// 合并升序链表
class MergeKLists {
public:

    struct comp {
        bool operator()(ListNode *p, ListNode *q) {
            return p->val > q->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode dummy;
        ListNode *p = &dummy;

        vector<ListNode *> heap;
        for (auto node: lists) {
            if (node)
                heap.push_back(node);
        }
        make_heap(heap.begin(), heap.end(), comp());

        while (!heap.empty()) {
            auto front = heap.front();
            p->next = front;
            pop_heap(heap.begin(), heap.end(), comp());
            heap.pop_back();

            if (front && front->next) {
                heap.push_back(front->next);
                push_heap(heap.begin(), heap.end(), comp());
            }

            p = p->next;
        }

        return dummy.next;
    }
};


// 接雨水
class Trap {
public:
    int trap(vector<int> &height) {
        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());

        int left = 0;
        for (int i = 0; i < height.size(); ++i) {
            leftMax[i] = left;
            left = max(left, height[i]);
        }

        int right = 0;
        for (int i = height.size() - 1; i >= 0; --i) {
            rightMax[i] = right;
            right = max(right, height[i]);
        }

        int res = 0;

        for (int i = 0; i < height.size(); ++i) {
            int nei = min(leftMax[i], rightMax[i]);
            res += nei > height[i] ? nei - height[i] : 0;
        }

        return res;
    }
};

// 两个正序数组的中位数
class FindMedianSortedArrays {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int mid1 = nums1[(0, nums1.size() - 1) >> 1];
        int mid2 = nums1[(0, nums2.size() - 1) >> 1];

        if (mid1==mid2)
            return mid1;


    }

    int find(vector<int> nums, int num, int left, int right) {

        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == num)
                return mid;

            if (nums[mid] < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }
};

#endif //CPP_AL_HPP
