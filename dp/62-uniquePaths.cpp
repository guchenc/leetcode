/*
 * @Description: 不同路径
 * @Author: guchen
 * @Date: 2020-11-04 19:32:10
 * @LastEditTime: 2020-11-04 19:32:21
 */
#include "../alg.h"

class Solution {
public:
    // DP 优化空间复杂度 space: O(n)
    int uniquePaths(int m, int n) {
        vector<int> cur(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cur[j] += cur[j - 1];   // cur[j] = cur[j - 1] + cur[j];
            }
        }
        return cur[n - 1];
    }
    // DP time: O(m * n) space: O(m * n)
    // dp[i][j]表示走到坐标(i, j)有多少种走法
    // dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
    // dp[0][j] = 1 dp[i][0] = 1
    int uniquePaths2(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // dp[0][0] = 0;
        // for (int i = 0; i < m; i++) dp[i][0] = 1;
        // for (int j = 0; j < n; j++) dp[0][j] = 1;
        // for (int i = 1; i < m; i++) {
        //     for (int j = 1; j < n; j++)
        //         dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        // }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    // DFS 超时 time: O(?) space: O(m + n)
    int uniquePaths1(int m, int n) {
        int pathcnt = 0;
        findPath(m, n, pathcnt, 1, 1);
        return pathcnt;
    }

    void findPath(int m, int n, int& pathcnt, int down, int right) {
        if (down == m && right == n) {
            pathcnt++;
            return;
        }
        if (down + 1 <= m) findPath(m, n, pathcnt, down + 1, right);
        if (right + 1 <= n) findPath(m, n, pathcnt, down, right + 1);
    }
};