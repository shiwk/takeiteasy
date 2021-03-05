//
// Created by shiwk on 2021/3/4.
//

#ifndef CPP_LINKLIST_HPP
#define CPP_LINKLIST_HPP

#include <stack>

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) :
            val(x), next(NULL) {
    }
};

class LinkList {
public:
    vector<int> printListFromTailToHead(ListNode *head) {
        vector<int> res;
        if (head == nullptr)
            return res;
        ListNode *p = head;
        ListNode *q = head->next;
        ListNode *k = nullptr;
        while (q != nullptr) {
            p->next = k;
            k = p;
            p = q;
            q = p->next;
        }

        p->next = k;

        while (p != nullptr) {
            res.push_back(p->val);
            p = p->next;
        }

        return res;
    }

    vector<int> printListFromTailToHead2(ListNode *head) {
        vector<int> res;

        stack<int> st;
        ListNode *p = head;
        while (p != nullptr) {
            st.push(p->val);
            p = p->next;
        }

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }

};

#endif //CPP_LINKLIST_HPP
