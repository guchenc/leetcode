/*
 * @Description: 杨辉三角
 * @Author: guchen
 * @Date: 2020-10-28 21:06:36
 * @LastEditTime: 2020-12-06 13:04:30
 */
#include "../alg.h"
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows < 1) return {};
        if (numRows == 1) return {{1}};
        vector<vector<int>> res = {{1}, {1, 1}};
        vector<int> row;
        int idx = 2;
        while (idx < numRows) {
            row.push_back(1);
            for (int i = 0; i < idx - 1; i++)
                row.push_back(res[idx - 1][i] + res[idx - 1][i + 1]);
            row.push_back(1);
            res.push_back(row);
            row.clear();
            idx++;
        }
        return res;
    }
    // 迭代，利用之前已经计算好的行，避免重复计算
    vector<vector<int>> generate2(int numRows) {
        vector<vector<int>> res = {{1}, {1, 1}};
        vector<int> row;
        if (numRows <= 0) return {};
        if (numRows == 1) return {{1}};
        if (numRows == 2) return {{1}, {1, 1}};
        int r = 3;
        while (r <= numRows) {
            row.push_back(1);
            for (int i = 0; i < r - 1; i++)
                row.push_back(res[r - 2][i] + res[r - 2][i + 1]);
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

int main()
{
    Solution s;
    vector<vector<int>> res = s.generate(10);
    for (auto r : res) {
        for (auto n : r) cout << n << " ";
        cout << endl;
    }
}