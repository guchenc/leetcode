/*
 * @Description: 最长上升子序列
 * @Author: guchen
 * @Date: 2020-11-06 18:20:37
 * @LastEditTime: 2020-11-06 18:21:05
 */
#include "../alg.h"
class Solution {
public:
    // DP
    // dp[i]表示以nums[i]结尾的最长升序子序列的长度
    // dp[i] = max{dp[k] + 1} (k < i && nums[k] < nums[i])
    // time: O(n^2) space: O(n)
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        int maxlen = 0;
        vector<int> dp(size, 1);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] >= nums[i]) continue;
                dp[i] = max(dp[i], dp[j] + 1);
            }
            maxlen = max(maxlen, dp[i]);
        }
        return maxlen;
    }
};