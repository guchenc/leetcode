/*
 * @Description: 最小路径和
 * @Author: guchen
 * @Date: 2020-12-10 20:28:13
 * @LastEditTime: 2020-12-10 20:28:39
 */
#include "../alg.h"
class Solution {
public:
    // 思路同3，简化版 time: O(m*n) space: O(1)
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int M = grid.size(), N = grid[0].size();
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (i == 0 && j == 0) continue; // skip (0,0)
                grid[i][j] += min(i == 0 ? INT_MAX : grid[i - 1][j], j == 0 ? INT_MAX : grid[i][j - 1]);
            }
        }
        return grid[M - 1][N - 1]; 
    }

    // 思路同1，直接在原地计算，进一步优化空间复杂度 time: O(m*n) space: O(1)
    int minPathSum3(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int M = grid.size(), N = grid[0].size();
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (i == 0 && j == 0) continue;
                else if (i == 0 && j != 0) grid[i][j] += grid[i][j - 1];
                else if (i != 0 && j == 0) grid[i][j] += grid[i - 1][j];
                else grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
            }
        }
        return grid[M - 1][N - 1]; 
    }

    // 思路同1，优化空间复杂度 time: O(m*n) space: O(n)
    int minPathSum2(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int M = grid.size(), N = grid[0].size();
        vector<vector<int>> dp(2, vector<int>(N + 1, INT_MAX)); // 只需要维护当前行和上一行
        int last = 0, cur = 1;
        dp[cur][0] = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++)
                dp[cur][j + 1] = grid[i][j] + min(dp[cur][j], dp[last][j + 1]);
            swap(cur, last);
        }
        return dp[last][N];
    }

    // DP time: O(m*n) space: O(m*n)
    // dp[i][j]表示到达(i,j)时的最小路径和
    // dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
    int minPathSum1(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int M = grid.size(), N = grid[0].size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, INT_MAX));
        dp[1][0] = 0;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) 
                dp[i][j] = grid[i - 1][j - 1] + min(dp[i][j - 1], dp[i - 1][j]);
        }
        return dp[M][N];
    }
};