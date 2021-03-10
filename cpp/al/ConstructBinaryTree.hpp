//
// Created by shiwk on 2021/3/7.
//

#ifndef CPP_CONSTRUCT_BINARY_TREE_HPP
#define CPP_CONSTRUCT_BINARY_TREE_HPP


#include <iostream>

//  Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode* left;
      TreeNode* right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

 
class ConstructBinaryTree {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.empty())
            return nullptr;

        TreeNode *root = reConstructBinaryTree(pre, vin, 0, 0, pre.size());
        return root;
//        bool isRight;
//        vector<int> left_pre;
//        vector<int> left_vin;
//        vector<int> right_pre;
//        vector<int> right_vin;
//
//        for (int i = 0; i < vin.size(); i++) {
//            if (vin[i] == pre[0])
//            {
//                isRight = true;
//                continue;
//            }
//            if (isRight) {
//                right_vin.push_back(vin[i]);
//                right_pre.push_back(pre[i]);
//            }
//            else {
//                left_vin.push_back(vin[i]);
//                left_pre.push_back(pre[i+1]);
//            }
//        }
//
//        if (!left_pre.empty())
//            root->left = reConstructBinaryTree(left_pre, left_vin);
//        if (!right_pre.empty())
//            root->right=reConstructBinaryTree(right_pre, right_vin);

//        return root;
    }

    TreeNode* reConstructBinaryTree(vector<int>& pre, vector<int>& vin, int preStart, int vinStart, int length) {

        TreeNode *root = new TreeNode(pre[preStart]);
        cout<<pre[preStart]<<endl;
        if (length == 1)
            return root;

        for (int i = 0; i < length; i++) {

            if (vin[vinStart + i] == pre[preStart])
            {
                if (i > 0)
                    root->left = reConstructBinaryTree(pre, vin, preStart+1, vinStart, i);
                if (i< length -1)
                    root->right = reConstructBinaryTree(pre, vin, preStart+i +1, vinStart + i+1, length - i -1);
            }
        }
        return root;
    }
};


#endif //CPP_CONSTRUCT_BINARY_TREE_HPP
