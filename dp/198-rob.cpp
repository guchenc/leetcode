/*
 * @Description: 打家劫舍
 * @Author: guchen
 * @Date: 2020-10-26 15:57:31
 * @LastEditTime: 2020-10-26 15:57:53
 */
#include "../alg.h"

class Solution {
public:
    // DP + 状态压缩 time: O(n) space: O(1)
    // 上一题解中dp[i]的值只与dp[i - 2]和dp[i]有关，因此没必要存储所有的结果
    int rob(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) return 0;
        if (N == 1) return nums[0];
        int dp[2];
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < N; i++) {
            int today = max(dp[0] + nums[i], dp[1]);
            dp[0] = dp[1];
            dp[1] = today;
        }
        return dp[1];
    }

    // DP
    // dp[i]表示偷到第i间房所能获得的最大金额
    // dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
    // time: O(n) space: O(n)
    int rob2(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int N = nums.size();
        vector<int> dp(N, 0);
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < N; i++)
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        return dp[N - 1];
    }

    // dp[i][0]和dp[i][1]表示i号房不偷与偷所能获得的最大金额
    // dp[0][0] = 0 dp[0][1] = nums[0]
    // dp[i][0] = max(dp[i - 1][0], dp[i - 1][1])
    // dp[i][1] = dp[i - 1][0] + nums[i]
    int rob1(vector<int>& nums) {
        if (nums.empty()) return 0;
        int N = nums.size();
        int dp[101][2] = {0};
        // vector<vector<int>> dp(N, vector<int>(2, 0));
        dp[0][0] = 0, dp[0][1] = nums[0];
        for (int i = 1; i < N; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        // for (int i = 0; i < N; i++) {
        //     cout << "idx:" << i << " " << dp[i][0] << dp[i][1] << endl;
        // }
        return max(dp[N - 1][0], dp[N - 1][1]);
    }
};