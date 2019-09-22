//
// Created by swk on 2019-09-21.
//

#ifndef CPP_STRTRIE_H
#define CPP_STRTRIE_H

#include <string>

namespace happycoding{
    struct TrieNode{
        int level;
        TrieNode* ptrs[128]{};
        explicit TrieNode(int l) : level(l){}
    };

    class Strtrie {
    public:
        Strtrie();
        void add(const std::string& str);
        bool match(const std::string& str, std::vector<std::string>& res);

    private:
        TrieNode *root;
    };
}



#endif //CPP_STRTRIE_H
