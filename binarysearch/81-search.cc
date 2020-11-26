/*
 * @Description: 搜索旋转排序数组II
 * @Author: guchen
 * @Date: 2020-11-26 20:19:03
 * @LastEditTime: 2020-11-26 20:20:30
 */
#include "../alg.h"
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;    // l <= m < r
            cout << "[" << l << ", " << r << "]  " << m << endl;
            if (nums[m] == target) return true;
            // 此时target可能位于[l, m)，(m, r],或者不存在; 需要判断位于哪一侧
            // 由于存在重复元素，无法直接根据nums[m]和nums[l]的大小关系来判断
            if (nums[l] < nums[m]) {
                if (nums[l] <= target && target < nums[m]) r = m - 1;
                else l = m + 1;
            } else if (nums[l] > nums[m]) {
                if (nums[m] < target && target <= nums[r]) l = m + 1;
                else r = m - 1;
            } else l++; // nums[l] == nums[m] 直接将l++即可，排除一个干扰项，缩小区间
        }
        return false;
    }

    bool search1(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return true;
            if (nums[l] < nums[m]) {
                if (nums[l] <= target && target <= nums[m]) r = m - 1;  // 因为之前已经判断过nums[m] != target，令r=m-1即可   
                else l = m + 1; 
            } else if (nums[l] > nums[m]) {
                if (nums[m] <= target && target <= nums[r]) l = m + 1;
                else r = m - 1;
            } else {
                // 当nums[m] == nums[l]时，无法判断是否有序，退化为顺序查找
                for (int i = l; i <= r; i++) {
                    if (nums[i] == target) return true;
                }
                return false;
            }
        }
        return false;
    }
};