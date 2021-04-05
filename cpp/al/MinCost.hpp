//
// Created by shiwk on 2021/3/14.
//

#ifndef CPP_MINCOST_HPP
#define CPP_MINCOST_HPP
#include <string>
class MinCost {
public:
    int minCost(string s, vector<int>& cost) {
        int res =0;
        int i =0;
        for (int j = 1; j < s.length(); ++j) {
            if (s[i]==s[j]) {
                if (cost[i] <= cost[j]) {
                    res += cost[i];
                    i = j;
                }
                else {
                    res += cost[j];
                }
            }
            else
                i=j;
        }

        return res;
    }
};
#endif //CPP_MINCOST_HPP
