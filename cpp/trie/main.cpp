//
// Created by swk on 2019-09-21.
//

#include <vector>
#include <iostream>
#include "Strtrie.h"

int main() {
    happycoding::Strtrie strtrie;
    const std::string str1 = "aa";
    strtrie.add(str1);

    const std::string str2 = "a";
    std::vector<std::string> res;
    bool isMatched= strtrie.match(str2, res);

    std::string matchingResult = isMatched ? "Success" : "Fail";
    std::cout<< matchingResult << std::endl;

    for (const auto& s : res) {
        std::cout << "Matched string: "<< s << std::endl;
    }
}