/*
 * @Description: 寻找旋转数组中的最小值
 * @Author: guchen
 * @Date: 2020-10-14 21:21:38
 * @LastEditTime: 2020-10-14 21:22:00
 */
#include <vector>
using namespace std;

class Solution {
public:
    // 二分查找 time: O(logn) space: O(1)
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        if (nums.size() == 1 || nums[l] < nums[r]) return nums[0];
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1]) return nums[mid + 1];
            if (nums[mid - 1] > nums[mid]) return nums[mid];
            if (nums[mid] > nums[0]) {
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return -1;
    }

    // time: O(n) space: O(1)
    int findMin1(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) return nums[i + 1];
        }
        return nums[0];
    }
};