/*
 * @Description: 搜索旋转排序数组
 * @Author: guchen
 * @Date: 2020-11-25 15:02:49
 * @LastEditTime: 2020-11-26 20:22:01
 */
#include "../alg.h"
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return m;
            if (nums[l] <= nums[m]) {
                if (nums[l] <= target && target <= nums[m]) r = m;
                else l = m + 1;
            } else {
                if (nums[m] <= target && target <= nums[r]) l = m;
                else r = m - 1;
            }
        }
        return -1;
    }

    // 二分查找，关键是如何确定丢弃哪一半
    // 旋转后的数组一切为二，其中一半一定是有序的，另一半可能有序也可能部分有序; 可以通过判断每一边的左右两个端点来判断该边是否有序
    int search1(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target == nums[mid]) return mid;
            if (mid - 1 >= l && nums[l] <= nums[mid - 1]) { // left is sorted
                if (target >= nums[l] && target <= nums[mid - 1]) r = mid - 1;  // target is in right half
                else l = mid + 1;
            } else {    // right is sorted
                if (target >= nums[mid] && target <= nums[r]) l = mid + 1;  // target is in left half
                else r = mid - 1;
            }
        }
        return -1;
    }
};