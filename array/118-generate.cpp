/*
 * @Description: 杨辉三角
 * @Author: guchen
 * @Date: 2020-10-14 19:13:37
 * @LastEditTime: 2020-10-14 19:14:00
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        if (numRows == 1) return {{1}};
        if (numRows == 2) return {{1}, {1, 1}};
        vector<vector<int>> res = {{1}, {1, 1}};
        vector<int> row;
        for (int i = 2; i < numRows; i++) {
            row.emplace_back(1);
            for (int j = 1; j < i; j++)
                row.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            row.emplace_back(1);
            res.emplace_back(row);
            row.clear();
        }
        return res;
    }
};