/*
 * @Description: 寻找旋转排序数组中的最小值
 * @Author: guchen
 * @Date: 2020-11-26 20:17:40
 * @LastEditTime: 2020-11-26 20:18:10
 */
#include "../alg.h"
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            if (nums[l] <= nums[r]) return nums[l];
            int m = l + (r - l) / 2;
            if (nums[l] <= nums[m]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return nums[l];
    }

    int findMin3(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int res = INT_MAX;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[l] <= nums[m]) {
                res = min(res, nums[l]);
                l = m + 1;
            } else {
                res = min(res, nums[m]);
                r = m - 1;
            }
        }
        return res;
    }

    //注意左右不对称，不过可以先通过比较nums[mid]和nums[l]得到最大值，最大值右边的值就是最小值(注意最大值在数组最右边的情况)
    int findMin2(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l + 1) / 2;    // 先加1再除，使得mid靠近r
            if (nums[m] > nums[l]) l = m;
            else r = m - 1;
        }
        return nums[(l + 1) % nums.size()];
    }

    //注意左右不对称，必须比较nums[mid]和nums[r]
    int findMin1(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) l = m + 1;
            else r = m;
            // 不能通过比较nums[m]和nums[l]来确定么?
        }
        return nums[r];
    }
};
