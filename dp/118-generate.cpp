/*
 * @Description: 杨辉三角
 * @Author: guchen
 * @Date: 2020-11-14 17:39:27
 * @LastEditTime: 2020-11-14 17:39:43
 */
#include "../alg.h"

class Solution {
public:
    // 迭代，利用之前已经计算好的行，避免重复计算
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res = {{1}, {1, 1}};
        vector<int> row;
        if (numRows <= 0) return {};
        if (numRows == 1) return {{1}};
        if (numRows == 2) return {{1}, {1, 1}};
        int r = 3;
        while (r <= numRows) {
            row.push_back(1);
            for (int i = 1; i < r - 1; i++)
                row.push_back(res[r - 2][i - 1] + res[r - 2][i]);
            row.push_back(1);
            res.push_back(row);
            row.clear();
            r++;
        }
        return res;
    }

    // 递归 超时 重复计算太多
    vector<vector<int>> generate1(int numRows) {
        vector<vector<int>> res;
        vector<int> row;
        for (int i = 1; i <= numRows; i++) {
            for (int j = 1; j <= i; j++)
                row.push_back(func(i, j));
            res.push_back(row);
            row.clear();
        }
        return res;
    }

    int func(int i, int j) {
        if (j == 1 || j == i) return 1;
        return func(i - 1, j - 1) + func(i - 1, j);
    }
};