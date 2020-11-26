/*
 * @Description: 寻找旋转排序数组中的最小值II
 * @Author: guchen
 * @Date: 2020-11-26 20:16:52
 * @LastEditTime: 2020-11-26 20:17:13
 */
#include "../alg.h"
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) l = m + 1;
            else if (nums[m] < nums[r]) r = m;
            else r--;
        }
        return nums[l];
    }

    int findMin1(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            while (l + 1 < r && nums[l + 1] == nums[l]) l++;
            while (r - 1 > l && nums[r - 1] == nums[r]) r--;
            if (nums[l] == nums[r]) {
                l++;
                continue;
            } 
            if (nums[l] < nums[r]) return nums[l];
            int m = l + (r - l) / 2;
            if (nums[l] <= nums[m]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return nums[l];
    }
};