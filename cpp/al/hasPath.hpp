//
// Created by shiwk on 2021/3/12.
//

#ifndef CPP_HASPATH_HPP
#define CPP_HASPATH_HPP

#include <string>

using namespace std;

class HasPath {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param matrix string字符串
     * @param rows int整型
     * @param cols int整型
     * @param str string字符串
     * @return bool布尔型
     */
    bool hasPath(string matrix, int rows, int cols, string str) {
        if (rows <= 0 || cols <= 0)
            return false;
        // write code here
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                bool *filled = new bool[rows * cols];
                if (hasPath(matrix, rows, cols, i, j, str, 0, filled))
                    return true;
            }
        }
        return false;
    }

private:
    bool hasPath(string &matrix, int rows, int cols, int row, int col, string &str, int pos, bool *filled) {
        int in = row * cols + col;
        char c = matrix[in];
        if (c != str[pos] || filled[in])
            return false;

        if (pos == str.length() - 1) {
            cout << c << endl;
            return true;
        }

        pos++;
        filled[in] = true;

        bool res = false;
        if (col > 0)
            res = hasPath(matrix, rows, cols, row, col - 1, str, pos, filled); // left

        if (!res && col < cols - 1)
            res = hasPath(matrix, rows, cols, row, col + 1, str, pos, filled); // right

        if (!res && row > 0)
            res = hasPath(matrix, rows, cols, row - 1, col, str, pos, filled); // up

        if (!res && row < rows - 1)
            res = hasPath(matrix, rows, cols, row + 1, col, str, pos, filled); // down

        if (!res) { filled[in] = false; }
        else
            cout << c << endl;

        return res;
    }
};

#endif //CPP_HASPATH_HPP
