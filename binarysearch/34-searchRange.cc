/*
 * @Description: 在排序数组中查找元素的第一个和最后一个位置
 * @Author: guchen
 * @Date: 2020-11-28 15:50:53
 * @LastEditTime: 2020-11-28 15:51:21
 */
#include "../alg.h"
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = binarySearch(nums, target);
        int r = binarySearch(nums, target + 1);
        if (l == nums.size() || nums[l] != target) return {-1, -1}; // 数组中不存在target
        // cout << l << " " << r << endl;
        return {l, r - 1};
    }

    // 二分查找，查找target序列的第一个下标
    int binarySearch(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] > target) r = m - 1;
            else if (nums[m] < target) l = m + 1;
            else {
                if (m == 0) return 0;
                if (nums[m - 1] < nums[m]) return m;
                else r = m - 1;
            }
        }
        return l;
    }

    // time: O(logn) space: O(1) 最坏情况下time: O(n)
    vector<int> searchRange1(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] > target) r = m - 1;
            else if (nums[m] < target) l = m + 1;
            else {
                // 找到后，向两边扩散
                int begin = m, end = m;
                while (begin - 1 >=0 && nums[begin - 1] == target) begin--;
                while (end + 1 < nums.size() && nums[end + 1] == target) end++;
                res[0] = begin;
                res[1] = end; 
                break;
            }
        }
        return res;
    }
};
