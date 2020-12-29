/*
 * @Description: 最大正方形
 * @Author: guchen
 * @Date: 2020-12-29 21:10:50
 * @LastEditTime: 2020-12-29 21:11:11
 */
#include "../alg.h"
class Solution {
public:
    // DP  time: O(r*c) space: O(r*c)
    // dp[i][j]表示以matrix[i][j]为右下角的正方形边长的最大值
    // dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1  如何理解?
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() && matrix[0].empty()) return 0;
        int maxEdge = 0;
        int R = matrix.size(), C = matrix[0].size();
        vector<vector<int>> dp(R + 1, vector<int>(C + 1, 0));   // 左边和上边各扩展一层，处理边界
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (matrix[i - 1][j - 1] == '0') continue;
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                maxEdge = max(maxEdge, dp[i][j]);
            }
        }
        return maxEdge * maxEdge;
    }

    // 暴力解法 time: O(?) space: O(?)
    int maximalSquare2(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int ret = 0;
        int R = matrix.size(), C = matrix[0].size();
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (matrix[i][j] == '0') continue;
                ret = max(ret, maxSquare(matrix, i, j));
                // cout << i << " " << j << ": " << ret << endl;
            }
        }
        return ret;
    }

    int maxSquare(vector<vector<char>>& matrix, int r, int c) {
        int R = matrix.size(), C = matrix[0].size();
        int ret = 1, k = min(R - 1 - r, C - 1 - c);
        cout << r << " " << c << " " << k << endl;
        for (int i = 1; i <= k; i++) {
            int r2 = r + i, c2 = c + i;
            for (int j = 0; j <= i; j++) {
                // cout << p << " " << j << " - " << j << " " << p << endl;
                // cout << j <<":" <<k<< " [" << r2 <<", " << c2 - j << "] " << "[" << r2 - j <<", " << c2 << "] " << endl;
                if (matrix[r2][c2 - j] == '0' || matrix[r2 - j][c2] == '0') return ret;
            }
            ret = pow(i + 1, 2);
        }
        return ret;
    }

    // 单调栈 
    int maximalSquare1(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int ret = INT_MIN;
        int R = matrix.size(), C = matrix[0].size();
        vector<vector<int>> digitMatrix(R, vector<int>(C + 1, 0));
        for (int j = 0; j < C; j++) {  // 对于每一行，自上往下统计每一列连续1的个数
            int height = 0;
            for (int i = 0; i < R; i++) {  
                if (matrix[i][j] == '1') digitMatrix[i][j] = ++height;
                else height = 0;
            }
        }
        for (int i = 0; i < R; i++)
            ret = max(ret, maxSquareInHistogram(digitMatrix[i]));
        return ret == INT_MIN ? 0 : ret;
    }

    int maxSquareInHistogram(vector<int>& row) {
        int ret = 0;
        stack<int> s;
        for (int i = 0; i < row.size(); i++) {
            while (!s.empty() && row[s.top()] > row[i]) {
                int width = 0, height = row[s.top()]; s.pop();
                if (s.empty()) width = i;
                else width = i - s.top() - 1;
                int edge = min(width, height);
                ret = max(ret, edge * edge);
            }
            s.push(i);
        }
        return ret;
    }
};