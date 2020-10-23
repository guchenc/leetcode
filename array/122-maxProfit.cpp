/*
 * @Description: 买卖股票的最佳时机
 * @Author: guchen
 * @Date: 2020-10-23 17:23:07
 * @LastEditTime: 2020-10-23 17:23:36
 */
#include "../alg.h"
class Solution {
public:
    // 贪心算法 time: O(n) space: O(1)
    int maxProfit(vector<int>& prices) {
        vector<pair<int, int>> record;
        int profit = 0;
        int buy = -1;
        for (int i = 0; i < prices.size(); i++) {
            if (i == prices.size() - 1) {
                if (buy != -1) record.push_back({buy, i + 1});
                break;
            } 
            if (prices[i] < prices[i + 1]) {
                if (buy == -1) buy = i + 1;
                profit += prices[i + 1] - prices[i];   
            }  else {
                if (buy != -1) {
                    record.push_back({buy, i + 1});
                    buy = -1;
                } 
            }
        }
        // for (auto n : record)
        //     cout << "buy:" << n.first << " sale:" << n.second << endl;
        // cout << "------------------------" << endl;
        return profit;
    }
};