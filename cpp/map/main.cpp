//
// Created by swk on 2019-07-25.
//

#include <iostream>
#include <random>
#include "linkmap.cpp"

using namespace std;
using namespace CryptoPP;

//string SHA256(string);

int main () {
    const int size = SHA256::DIGESTSIZE;
    happycoding::linkmap<int, string> linkmap(size);
    const int n = 100;
    for (int i = 0; i <= n; ++i) {
        linkmap[i] = to_string(i) + "_abc";
    }

    std::random_device rd;
    std::mt19937_64 mt(rd());
    std::uniform_int_distribution<int> dist(0, n);
    int i = 0;
    while (i++ < n )
    {
        int k = dist(mt);
        string str = linkmap.get(k);
        std::cout<< "map["<< k <<"]" <<" = " <<  str << endl;
        linkmap[k] = to_string(k);
        std::cout<< "map["<< k <<"]" <<" = " <<  linkmap[k] << endl;

        linkmap.remove(k);
        std::cout<< "after remove," << endl;
        string str2 = linkmap[k];
        std::cout<< "map["<< k <<"]" <<" = " <<  str2 << endl;

        std::cout<<endl;
    }

    string str = linkmap[n + 1];
    std::cout<< "map["<< n + 1 <<"]" <<" = " <<  str << endl;
    linkmap[n + 1] = to_string(n+1);
    std::cout << "after set: " << str << endl;
    str = linkmap[n + 1];
    std::cout<< "map["<< n + 1 <<"]" <<" = " <<  str << endl;

    return 0;
}
