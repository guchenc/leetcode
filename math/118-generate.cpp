/*
 * @Description: 杨辉三角
 * @Author: guchen
 * @Date: 2020-10-28 21:06:36
 * @LastEditTime: 2020-10-28 21:06:52
 */
#include "../alg.h"
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res = {{1}, {1, 1}};
        vector<int> row;
        int cnt;
        if (numRows < 1) return {};
        if (numRows == 1) return {{1}};
        if (numRows == 2) return {{1}, {1, 1}};
        cnt = 3;
        while (cnt <= numRows) {
            row.push_back(1);
            for (int i = 0; i < cnt - 2; i++)
                row.push_back(res[cnt - 2][i] + res[cnt - 2][i + 1]);
            row.push_back(1);
            res.push_back(row);
            row.clear();
            cnt++;
        }
        return res;
    }
};