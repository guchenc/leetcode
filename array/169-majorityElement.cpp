/*
 * @Description:多数元素
 * @Author: guchen
 * @Date: 2020-11-09 17:30:40
 * @LastEditTime: 2020-11-09 17:30:55
 */
#include "../alg.h"
class Solution {
public:
    // 摩尔投票法
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int candidate = -1;
        for (auto n : nums) {
            if (cnt == 0) {
                candidate = n;
                cnt++;
            } else {
                if (n == candidate) cnt++;
                else cnt--;
            }
        }
        return candidate;
    }

    // time: O(nlogn) space: O(logn)
    int majorityElement1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};