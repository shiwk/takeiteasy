//
// Created by swk on 2019-05-26.
//

#include "Stringdistance.h"
#include <algorithm>    // std::min
#include <iostream>

namespace happycoding{
    int Stringdistance::minDistance(string word1, string word2) {
        const int length1 = word1.size() + 1;
        const int length2 = word2.size() + 1;

        int arr[length1][length2];
        for (int i = 0; i < length1; ++i) {
            for (int j = 0; j < length2; ++j) {
                if(i == 0 || j == 0)
                    arr[i][j]  = i|j;
                else {
                    if(word1[i - 1] == word2 [j - 1])
                        arr[i][j] = arr[i-1][j-1];
                    else
                        arr[i][j] = min(arr[i][j-1], min(arr[i-1][j], arr[i-1][j-1])) + 1;
                }<

                //cout << arr[i][j] << " ";
            }
            //cout << endl;
        }
        return arr[length1 -1][length2 - 1];
    }
}
