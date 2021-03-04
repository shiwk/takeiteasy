//
// Created by shiwk on 2021/3/3.
//

#ifndef CPP_FINDREPEATED_HPP
#define CPP_FINDREPEATED_HPP

#include <vector>

using namespace std;

class FindRepeated {
public:
    int find(vector<int> &arr) {
        return find(arr, 1, arr.size() - 1);
    }

private:
    int find(vector<int> &arr, int start, int end) {
        if (start == end)
            return start;
        int med = (start + end) / 2;
        int lessThanThanMed = 0;
        for (int i : arr) {
            if (i <= med && i >= start)
                lessThanThanMed++;
        }

        if (lessThanThanMed > med - start + 1)
            return find(arr, start, med);
        else
            return find(arr, med + 1, end);
    }
};

#endif //CPP_FINDREPEATED_HPP
