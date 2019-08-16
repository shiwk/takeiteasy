//
// Created by swk on 2019-05-26.
//

#include "huffman.h"
#include <queue>

using namespace std;

template <typename T>
class mycomparison
{
    bool reverse;
public:
    mycomparison(const bool& revparam=false)
    {reverse=revparam;}
    bool operator() (const Node<T>* lhs, const Node<T>*rhs) const
    {
        if (reverse) return (lhs->freq > rhs->freq);
        else return (lhs->freq < rhs->freq);
    }
};

namespace happycoding{

    template <typename T>
    Node<T>* getNode(T ch, int freq, Node<T>* left, Node<T>* right)
    {
        Node<T>* node = new Node<T>();

        node->ch = ch;
        node->freq = freq;
        node->left = left;
        node->right = right;

        return node;
    }

    template <typename T>
    void huffman<T> ::encode(Node<T> *root, string str, unordered_map<T, string> &huffmanCode) {
        if (root == nullptr)
            return;
        if(root -> left == nullptr && root -> right == nullptr)
            huffmanCode[root -> ch] = str;

        encode(root -> left, str + '0', huffmanCode);
        encode(root -> right, str + '1', huffmanCode);
    }

    template <typename T>
    T huffman<T> ::decode(Node<T> *root, int &index, string str) {
        if(root -> left == nullptr && root -> right == nullptr)
            return root -> ch;

        if(str[index] == '0')
            return decode(root -> left, ++index, str);
        else
            return decode(root -> right, ++index, str);
    }

    template <typename T>
    Node<T>* huffman<T> ::buildtree(string str) {
        priority_queue<Node<T>*, std::vector<Node<T>*>, mycomparison<T>> queue(mycomparison<char>(true));
        unordered_map<T, int> count_map;

        for (int i = 0; i < str.size(); ++i) {
            if(count_map.find(str[i]) == count_map.end())
                count_map.insert({str[i], 1});
            else
                count_map[str[i]] = count_map[str[i]] + 1;
        }

        for(auto pair : count_map)
        {
            Node<T>* node = getNode<T>(pair.first, pair.second, nullptr, nullptr);
            queue.push(node);
        }

        while (queue.size() != 1)
        {
            Node<T> *node1 = queue.top();
            queue.pop();
            Node<T> *node2 = queue.top();
            queue.pop();

            Node<T>* new_node = getNode<T>(0, node1->freq + node2->freq, node2, node1);
            queue.push(new_node);
        }
        return queue.top();
    }


}