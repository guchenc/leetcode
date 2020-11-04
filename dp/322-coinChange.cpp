/*
 * @Description: 零钱兑换
 * @Author: guchen
 * @Date: 2020-11-04 19:29:54
 * @LastEditTime: 2020-11-04 19:31:35
 */
#include "../alg.h"
class Solution {
public:
    // 递归 + 贪心 解法出错
    int mincnt = -1;
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.rbegin(), coins.rend());
        pickcoin(coins, amount, 0, 0);
        return mincnt;
    }

    bool pickcoin(vector<int>& coins, int amount, unsigned total, int cnt) {
        if (total > amount) return false;
        if (total == amount) {
            mincnt = cnt;
            return true;
        }
        for (auto& c : coins)   // 贪心算法，为了获得最少的硬币数，每次从面额最大的硬币开始尝试
            if (pickcoin(coins, amount, total + c, cnt + 1)) return true;
        return false;
    }

    int coinChange2(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount + 1, 0);
        for (auto c : coins) {
            if (c > amount) continue;
            dp[c] = 1;
        } 
        for (int i = 1; i <= amount; i++) {
            int mincnt = dp[i] == 0 ? INT_MAX : dp[i];
            for (auto& c : coins) {
                if (i - c < 0 || dp[i - c] == 0)  continue;
                mincnt = min(mincnt, dp[i - c] + 1);
            }
            dp[i] = (mincnt == INT_MAX) ? 0 : mincnt;
        }
        return dp[amount] == 0 ? -1 : dp[amount];
    }

    // DP
    // dp[i]表示可以凑成总金额i的最少硬币数
    // dp[i] = min{dp[i - coins[k]] + 1}
    int coinChange1(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX - 10);
        dp[0] = 0;
        for (auto c : coins) {
            if (c > amount) continue;
            dp[c] = 1;
        } 
        for (int i = 1; i <= amount; i++) {
            for (auto& c : coins) {
                if (i - c < 0)  continue;
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
        return dp[amount] == INT_MAX - 10 ? -1 : dp[amount];
    }
};