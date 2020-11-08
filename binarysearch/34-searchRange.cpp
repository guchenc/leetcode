/*
 * @Description: 在排序数组中查找元素的第一个和最后一个位置
 * @Author: guchen
 * @Date: 2020-11-08 18:43:03
 * @LastEditTime: 2020-11-08 18:43:20
 */
#include "../alg.h"

class Solution {
public:
    // 
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.size() == 0) return res;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[l] != target) return res;
        res[0] = l;
        r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) l = mid + 1;
            else r = mid;
        }
        res[1] = l - 1;
        return res;
    }

    // 先通过二分查找找到一个目标元素的位置，再通过向左右扩散，找到序列起始坐标，最坏情况下time:O(n)
    vector<int> searchRange1(vector<int>& nums, int target) {
        vector<int> res;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                l = r = mid;
                while (l - 1 >= 0 && nums[l - 1] == target) l--;
                res.push_back(l);
                while (r + 1 < nums.size() && nums[r + 1] == target) r++;
                res.push_back(r);
                return res;
            }
        }
        return {-1, -1};
    }
};