/*
 * @Description: 不同路径II
 * @Author: guchen
 * @Date: 2020-12-10 20:29:35
 * @LastEditTime: 2020-12-10 20:29:51
 */
#include "../alg.h"
class Solution {
public:
    // DP time: O(m*n) space: O(m*n)
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        int M = obstacleGrid.size(), N = obstacleGrid[0].size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0)); // 在最左侧和最上侧多添加一列和一行
        dp[1][0] = 1;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (obstacleGrid[i - 1][j - 1] == 1) {
                    // cout << "- ";
                    continue;  // 障碍物到达不了，直接跳过
                } 
                if (j == 1 || obstacleGrid[i - 1][j - 2] == 0) dp[i][j] += dp[i][j - 1];    // 注意边界问题如何解决
                if (i == 1 || obstacleGrid[i - 2][j - 1] == 0) dp[i][j] += dp[i - 1][j];
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        return dp[M][N];
    }
};