/*
 * @Description: 搜索插入位置
 * @Author: guchen
 * @Date: 2020-12-03 15:35:24
 * @LastEditTime: 2020-12-03 15:35:33
 */
#include "../alg.h"
class Solution {
public:
    // time: O(long) space: O(1)
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) { // 返回下标介于[0, nums.size()]，不断缩小区间范围
            int m = l + (r - l) / 2;
            if (nums[m] > target) r = m;    // 返回的下标只可能位于[l, m]
            else if (nums[m] < target) l = m + 1;   // l不断逼近目标位置 返回的下标只可能位于[m + 1, r]
            else return m;
        }
        return l;
    }
};
