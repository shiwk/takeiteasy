//
// Created by swk on 2019-09-21.
//

#include <vector>
#include <iostream>
#include "Strtrie.h"

namespace happycoding{
    void addChild(TrieNode* n, int index, const std::string& str);
    void matchChild(TrieNode* n, const std::string& str, std::vector<std::string>& res);
    TrieNode* find(TrieNode* n, const std::string& str, int index);

    void Strtrie :: add(const std::string& str){
        addChild(root, 0, str);
    }

    bool Strtrie :: match(const std::string& str, std::vector<std::string>& res){
        auto node = find(root, str, 0);
        if (node == nullptr)
            return false;

        matchChild(node, str, res);
        return true;
    }

    Strtrie :: Strtrie() {
        root = new TrieNode(-1);
    }

    TrieNode* find(TrieNode* n, const std::string& str, int index){
        if(index >= str.length())
        {
            return n;
        }

        int c = str[index];

        if(n->ptrs[c] == nullptr) {
            return nullptr;
        }
        return find(n->ptrs[c], str, index + 1);
    }

    void matchChild(TrieNode* n, const std::string& str, std::vector<std::string>& res){
        for (int i = 0; i < 128; ++i) {
            auto node = n->ptrs[i];
            if(node != nullptr){
                const std::string s = str + (char)i;
                res.push_back(s);
                matchChild(node, s, res);
            }
        }
    }

    void addChild(TrieNode * n, int index, const std::string& str) {
        if (index >= str.length())
            return;
        int i = str[index];
        auto child = n->ptrs[i];
        if(child == nullptr){
            n->ptrs[i] = new TrieNode(index);
        }
        addChild(n->ptrs[i], index + 1, str);
    }
}