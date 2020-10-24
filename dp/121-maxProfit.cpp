/*
 * @Description: 买卖股票的最佳时机
 * @Author: guchen
 * @Date: 2020-10-24 15:29:10
 * @LastEditTime: 2020-10-24 15:29:38
 */
#include "../alg.h"
class Solution {
public:
    // DP
    // dp[i] [0, i]天的可以获得的最大利润
    // dp[i] = max(dp[i - 1], prices[i] - minprice)  (1 <= i < prices.size())
    // dp[0] = 0; minprice = prices[0] 
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 1) return 0;
        vector<int> dp(prices.size(), 0);
        int minprice = prices[0];
        dp[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[i] = max(dp[i - 1], prices[i] - minprice);
            minprice = min(minprice, prices[i]);
        }
        // for (auto n : dp) cout << n << " ";
        // cout << endl;
        return dp[prices.size() - 1];
    }

    // 遍历股票走势 time: O(n) space: O(1)
    // - 记录之前的最小股价(包括当天)
    // - 更新最高股差
    int maxProfit2(vector<int>& prices) {
        int min = INT_MAX, protfit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min) min = prices[i];
            protfit = max(prices[i] - min, protfit);
        }
        return protfit;
    }

    // 暴力枚举 time: O(n^2) space: O(1)
    int maxProfit1(vector<int>& prices) {
        int protfit = 0;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                protfit = max(prices[j] - prices[i], protfit);
            }
        }
        return protfit;
    }
};