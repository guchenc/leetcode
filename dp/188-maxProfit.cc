/*
 * @Description: 买卖股票的最佳时间IV
 * @Author: guchen
 * @Date: 2020-12-29 21:15:12
 * @LastEditTime: 2020-12-29 21:15:28
 */
#include "../alg.h"
class Solution {
public:
    // DP
    // trade[i][0]表示第i次交易买入时的最大收益
    // trade[i][1]表示第i次交易卖出时的最大收益
    // trade[i][0] = max(trade[i][0], trade[i - 1][1] - prices[i])
    // trade[i][1] = max(trade[i][1], trade[i][0] + prices[i])
    int maxProfit(int k, vector<int>& prices) {
        if (k < 1) return 0;
        if (k >= prices.size() / 2) return greedy(prices); // 这里如何理解？
        vector<vector<int>> trade(k, vector<int>(2, 0));
        for (int i = 0; i < k; i++) trade[i][0] = INT_MIN;  // 为啥这一步必须？
        int ret = 0;
        for (auto p : prices) {
            trade[0][0] = max(trade[0][0], -p);
            trade[0][1] = max(trade[0][1], trade[0][0] + p);
            for (int j = 1; j < k; j++) {
                trade[j][0] = max(trade[j][0], trade[j - 1][1] - p);
                trade[j][1] = max(trade[j][1], trade[j][0] + p);
                // cout << j << ": " << trade[j][0] << " " << trade[j][1] << endl;
                // ret = max(ret, trade[j][1]);
            }
        }
        // return ret;
        return trade[k - 1][1];
    }

    int greedy(vector<int>& prices) {
        int maxProfit = 0;       
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1])
                maxProfit += prices[i] - prices[i - 1];
        }
        return maxProfit;
    }
};