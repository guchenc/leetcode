/*
 * @Description: 秋叶收藏集 
 * @Author: guchen
 * @Date: 2020-10-04 15:58:15
 * @LastEditTime: 2020-10-04 17:00:50
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // DP time: O(n) space: O(n)
    // 状态: 使用3个数组来维护状态转移
    //      - dp[0][i]表示将枫叶序列[0..i]调整为全红所需要的最少调整次数
    //      - dp[1][i]表示将枫叶序列[0..i]调整为红黄所需要的最少调整次数
    //      - dp[2][i]表示将枫叶序列[0..i]调整为红黄红所需要的最少调整次数
    // 状态转移函数:
    //      - dp[0][i] = dp[0][i-1] + isYellow(i)
    //      - dp[1][i] = min(dp[0][i-1], dp[1][i-1]) + isRed(i)
    //      - dp[2][i] = min(dp[1][i-1], dp[2][i-1]) + isYellow(i)
    // 边界条件: 全红状态，红黄状态，红黄红状态分别至少需要1, 2, 3片叶子
    // 初始化: dp[i][j] = 0
    int minimumOperations(string leaves) {
        vector<vector<int>> dp(3, vector<int>(leaves.size(), 0));
        for (int i = 0; i < leaves.size(); i++) {
            if (i < 1) dp[0][i] = (leaves[i] == 'y');
            else dp[0][i] = dp[0][i - 1] + (leaves[i] == 'y');

            if (i < 1) dp[1][i] = INT32_MAX;    // 红黄状态至少需要两片叶子
            else dp[1][i] = min(dp[0][i - 1], dp[1][i - 1]) + (leaves[i] == 'r');

            if (i < 2) dp[2][i] = INT32_MAX;    // 红黄红状态至少需要三片叶子
            else dp[2][i] = min(dp[1][i - 1], dp[2][i - 1]) + (leaves[i] == 'y');
        }
        // print_dp(dp);
        return dp[2][leaves.size() - 1];
    }

    void print_dp(vector<vector<int>>& dp) {
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                if (dp[i][j] == INT32_MAX) cout << "* ";
                else cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
};

