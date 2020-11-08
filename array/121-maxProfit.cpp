/*
 * @Description: 买卖股票的最佳时机
 * @Author: guchen
 * @Date: 2020-11-08 18:44:37
 * @LastEditTime: 2020-11-08 18:45:15
 */
#include "../alg.h"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int profit = 0;
        int minp = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minp) minp = prices[i];
            else if (prices[i] > minp) {
                profit = max(profit, prices[i] - minp);
            }
        }
        return profit;
    }
};