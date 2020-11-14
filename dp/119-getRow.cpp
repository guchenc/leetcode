/*
 * @Description: 杨辉三角II
 * @Author: guchen
 * @Date: 2020-11-14 17:37:08
 * @LastEditTime: 2020-11-14 17:39:06
 */
#include "../alg.h"
class Solution {
public:
    // DP time: O(n^2) space: O(n)
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp(2, vector<int>(rowIndex + 1, 0));
        for (int i = 1; i <= rowIndex + 1; i++) {
            for (int j = 1; j <= i; j++) {
                if (j == 1 || j == i) dp[1][j - 1] = 1;
                else dp[1][j - 1] = dp[0][j - 2] + dp[0][j - 1];
            }
            dp[0].swap(dp[1]);  // 只是交换vecto中的数据块指针，常数时间
        }       
        return dp[0];
    }

    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        if (rowIndex == 1) return {1, 1};
        vector<int> row = {1, 1};
        vector<int> nrow;
        for (int i = 2; i <= rowIndex; i++) {
            nrow.emplace_back(1);
            for (int j = 1; j < row.size(); j++)
                nrow.emplace_back(row[j - 1] + row[j]);
            nrow.emplace_back(1);
            row.assign(nrow.begin(), nrow.end());
            nrow.clear();
        }
        return row;
    }
};
