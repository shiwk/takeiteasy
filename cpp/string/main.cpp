//
// Created by swk on 2019-08-23.
//

#include "bfmatch.cpp"
#include "rkmatch.cpp"
#include "bmmatch.cpp"
#include <iostream>

void testBfMatch()
{
    happycoding::BfMatch bfMatch;
    const unsigned int textSize = 3;
    const unsigned int patternSize = 2;

    char text[textSize] = {'2', '1', '2'};
    char pattern [patternSize] = {};
    std::cout<< bfMatch.indexOf(text, textSize, pattern, patternSize);
}

int testRkMatch(const char* text, unsigned int textSize, const char* pattern, unsigned int patternSize)
{
    happycoding::RkMatch rkMatch;
    int res = rkMatch.indexOf(text, textSize, pattern, patternSize);
    return res;
}

int testBmMatch(const char* text, unsigned int textSize, const char* pattern, unsigned int patternSize)
{
    happycoding::BmMatch bmMatch;
    int res = bmMatch.indexOf(text, textSize, pattern, patternSize);
    return res;
}

int main(){
//    const unsigned int textSize = 100;
//    unsigned int patternSize;
//
//    unsigned int range = 82;
//    std::random_device rd;
//    std::mt19937_64 mt(rd());
//    std::uniform_int_distribution<int> dist(0, range);
//    char text[textSize];
//    char c0 = 40;
//    for (unsigned int i = 0; i < textSize; ++i) {
//        int r =dist(mt);
//        text[i] = static_cast<char> (40 + r);
//        std :: cout<< i <<": (" << text[i] << ", " << 40 + r << ") ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//
//    while (true)
//    {
//        std::cout<< "pattern size: ";
//        std::cin >> patternSize;
//        char pattern[patternSize];
//
//        unsigned int k = 0;
//        while (k < patternSize){
//            int c;
//            std::cout<< "character " << k + 1<< ": ";
//            std::cin>> c;
//            pattern[k++] = static_cast<char >(c);
//        }
//        std::cout<<"pattern: ";
//        for (unsigned int i = 0; i < patternSize; ++i) {
//            std::cout << pattern[i];
//        }
//        std::cout<<std::endl;
//        int res = testBmMatch(text, textSize, pattern, patternSize);
//        std::cout<< "Result: "<< res << std::endl;
//        std::cout <<std::endl;
//    }

    const unsigned int textSize = 7;


    char text[textSize] = {'2', '1', '1', '3', '1','1', '3'};
    happycoding::BmMatch bmMatch;

    const unsigned int patternSize0 = 1;
    char pattern0 [patternSize0] = {'1'};
    std::cout<< testBmMatch(text, textSize, pattern0, patternSize0)<<std::endl;

    const unsigned int patternSize1 = 2;
    char pattern1 [patternSize1] = { '1', '2'};
    std::cout<< testBmMatch(text, textSize, pattern1, patternSize1) <<std::endl;

    const unsigned int patternSize2 = 2;
    char pattern2 [patternSize2] = { '2', '2'};
    std::cout<< testBmMatch(text, textSize, pattern2, patternSize2) <<std::endl;

    const unsigned int patternSize3 = 3;
    char pattern3 [patternSize3] = { '2', '1', '3'};
    std::cout<< testBmMatch(text, textSize, pattern3, patternSize3) <<std::endl;

    const unsigned int patternSize4 = 3;
    char pattern4 [patternSize4] = { '3', '1', '1'};
    std::cout<< testBmMatch(text, textSize, pattern4, patternSize4) <<std::endl;

    const unsigned int patternSize5 = 4;
    char pattern5 [patternSize5] = { '3', '1', '1', '3'};
    std::cout<< testBmMatch(text, textSize, pattern5, patternSize5) <<std::endl;
}