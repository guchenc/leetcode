/*
 * @Description: 寻找峰值
 * @Author: guchen
 * @Date: 2020-11-08 18:43:51
 * @LastEditTime: 2020-11-08 18:44:09
 */
#include "../alg.h"
class Solution {
public:
    // 迭代二分查找，上左/右坡一侧必有峰值!
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l != r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1]) r = mid;
            else l = mid + 1;
            // if (nums[mid] > nums[mid - 1]) l = mid;  // 为什么这个不行 除法向下求整？例如数组大小为2 (0 + 1) / 2 = 0
            // else r = mid - 1;
        }
        return l;
    }

    int findPeakElement2(vector<int>& nums) {
        return findPeak(nums, 0, nums.size() - 1);
    }
    
    int findPeak(vector<int>& nums, int l, int r) {
        if (l == r) return l;
        int mid = l + (r - l) / 2;
        if (nums[mid] > nums[mid + 1]) {
            return findPeak(nums, l, mid);
        } else {
            return findPeak(nums, mid + 1, r);
        }
    }

    // 暴力解法，不符合要求 time: O(n) space: O(1)
    int findPeakElement1(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) 
            if ((i == 0 || nums[i] > nums[i - 1]) && (i == nums.size() - 1 || nums[i] > nums[i + 1])) return i;
        return -1;
    }
};