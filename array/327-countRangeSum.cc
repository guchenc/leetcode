/*
 * @Description: 区间和的个数
 * @Author: guchen
 * @Date: 2020-11-28 15:52:31
 * @LastEditTime: 2020-11-28 15:52:55
 */
#include "../alg.h"

class Solution {
public:
    // 暴力解法-前缀和
    // S(i,j) = S(j,0) - S(i - 1,0) = P(j) - P(i - 1)
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) return 0;
        unordered_map<int, long> preSum;
        preSum[-1] = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= lower && nums[i] <= upper) res++;    // 在计算前缀和的过程中顺便计算单个元素区间的情况
            preSum[i] = preSum[i - 1] + nums[i];
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                long sum = preSum[j] - preSum[i - 1];
                if (sum >= lower && sum <= upper) res++;
            }
        }
        return res;
    }

    // 暴力解法-枚举 time: O(n^2) space: O(1)
    int countRangeSum1(vector<int>& nums, int lower, int upper) {
        int N = nums.size();
        int res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (i == j) { 
                    if (nums[i] >= lower && nums[i] <= upper)
                        res++;
                } else {
                    long sum = accumulate(nums.begin() + i, nums.begin() + j + 1,(long)0);
                    if (sum >= lower && sum <= upper) res++;
                }
            }
        }
        return res;
    }
};