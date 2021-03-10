//
// Created by swk on 2019-05-26.
//

#include <iostream>
#include "huffman.h"

using namespace std;
int main(){

    happycoding::huffman<char> huffman;
    string orignal = "Huffman coding is a data compression algorithm.";
    cout<< endl << endl << "--------- Orignal string ---------" <<endl;
    cout<< orignal << endl << endl;


    Node<char>* node = huffman.buildtree(orignal);

    unordered_map<char, string> unorderedMap;

    huffman.encode(node, "", unorderedMap);

    cout << "--------- Encode ----------" << endl;
    for (const auto& kv : unorderedMap) {
        cout << kv.first << " : " << kv.second << endl;
    }

    string encoded;
    for (char i : orignal)
    {
        encoded += unorderedMap[i];
    }

    cout<< endl << endl << "--------- Encoded string ---------" <<endl;
    cout<< encoded;


    string decoded;
    for (int j = 0; j < encoded.size(); ) {
        decoded += huffman.decode(node, j, encoded);
    }
    cout<< endl << endl << "--------- Decoded string ---------" <<endl;
    cout<< decoded<< endl << endl;

    cout << orignal.compare(decoded);
}