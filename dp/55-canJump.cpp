/*
 * @Description: 跳跃游戏
 * @Author: guchen
 * @Date: 2020-10-24 15:26:01
 * @LastEditTime: 2020-10-24 15:27:50
 */
#include "../alg.h"
class Solution {
public:
    // 遍历数组，记录当前可以跳达的最远位置
    bool canJump(vector<int>& nums) {
        int reached = 0;
        for (int i = 0; i < nums.size() && reached < nums.size() - 1; i++) {
            if (i > reached) return false;
            reached = max(i + nums[i], reached);
        }
        // return reached >= nums.size() - 1 ? true : false;
        return true;
    }
    // DP
    // dp[i]表示从位置i开始可以到达的最远距离
    // dp[i] = sum{dp[j]} (i <= j < T-1)
    // bool canJump1(vector<int>& nums) {
    //     if (nums.size() < 2) return true;
    //     vector<int> dp(nums.size(), 0);
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (nums[i] == 0) continue;
    //         for (int j = i; j < nums.size(); j += nums[j]) {
    //             if (nums[j] == 0) break;
    //             dp[i] += nums[j];
    //         }
    //     }
    //     for (int i = 0; i < nums.size() - 1; i++) {
    //         for (int j = i; j < j + dp[j]; j++) {
    //             if (nums.size() - 1 - j <= dp[j])
    //                 return true;
    //         }
    //     }
    //     return false;
    // }
};