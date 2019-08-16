//
// Created by swk on 2019-05-26.
//

#ifndef CPP_LTC_HUFFMAN_H
#define CPP_LTC_HUFFMAN_H


#include <string>
#include <unordered_map>

using namespace std;

template <typename T>
struct Node
{
//    Node(const T c, const int f) :ch(c), freq(f){}
//    Node(const int f) : freq(f){}

    T ch;
    int freq;

    Node<T> * left, * right;
};


namespace happycoding{

    template <typename T>
    class huffman {
    public:
        T decode(Node<T>* root, int &index, string str);
        void encode(Node<T>* root, string str, unordered_map<T, string> &huffmanCode);
        Node<T>* buildtree(string str);
    };
}



#endif //CPP_LTC_HUFFMAN_H
