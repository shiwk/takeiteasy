//
// Created by shiwk on 2021/3/9.
//

#ifndef CPP_SIMPLEQUEUE_HPP
#define CPP_SIMPLEQUEUE_HPP
#include <stack>
#include <exception>
using namespace std;
class SimpleQueue{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                int top = stack1.top();
                stack2.push(top);
                stack1.pop();
            }

            if (stack2.empty())
                throw exception();
        }

        int top  = stack2.top();
        stack2.pop();
        return top;
    }


private:
    stack<int> stack1;
    stack<int> stack2;
};

#endif //CPP_SIMPLEQUEUE_HPP
