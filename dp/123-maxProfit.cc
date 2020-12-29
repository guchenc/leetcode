/*
 * @Description: 买卖股票的最佳时机III
 * @Author: guchen
 * @Date: 2020-12-29 21:16:17
 * @LastEditTime: 2020-12-29 21:16:36
 */
#include "../alg.h"
class Solution {
public:
    // left_right[i]表示[0...i]的单次交易的最大利润
    // right_left[i]表示[i...N - 1]的单次交易的最大利润
    int maxProfit(vector<int>& prices) {
        int ret = INT_MIN;
        int N = prices.size();
        vector<int> left_right(N, 0), right_left(N, 0);
        int minPrice = prices[0], maxPrice = prices[N - 1];
        for (int i = 1; i < N; i++) {
            minPrice = min(minPrice, prices[i]);
            left_right[i] = max(left_right[i - 1], prices[i] - minPrice);
        }
        for (int i = N - 2; i >= 0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            right_left[i] = max(right_left[i + 1], maxPrice - prices[i]);
        }

        for (int i = 0; i < N; i++)
            ret = max(ret, left_right[i] + right_left[i]);
        return ret;
    }

    // 简化的DP，维护四个变量
    // firBuy: 第一次买时的最大利润
    // firSale: 第一次卖时的最大利润
    // secBuy: 第二次买时的最大利润
    // secSale: 第二次卖时的最大利润
    int maxProfit2(vector<int>& prices) {
        int firBuy = INT_MIN, firSale = 0;
        int secBuy = INT_MIN, secSale = 0;
        for (auto p : prices) {
            firBuy = max(firBuy, -p);
            firSale = max(firSale, firBuy + p);
            secBuy = max(secBuy, firSale - p);
            secSale = max(secSale, secBuy + p);
        }
        return secSale;
    }

    // DP 超时
    int maxProfit1(vector<int>& prices) {
        int N = prices.size();
        // 天数-当前交易次数（0/1/2）-持股/不持股的最大利润 
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(3, vector<int>(2)));   
        dp[0][0][0] = 0;
        dp[0][0][1] = -prices[0];
        dp[0][1][0] = 0;
        dp[0][1][1] = -prices[0];
        dp[0][2][0] = 0;
        dp[0][2][1] = -prices[0];
        for (int i = 1; i < N; i++) {
            dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][0][0] - prices[i]);
            dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][0][1] + prices[i]);
            dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][1][0] - prices[i]);
            dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][1][1] + prices[i]);
        }
        return dp[N - 1][2][0];
    }
};