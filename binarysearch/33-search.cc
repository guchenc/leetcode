/*
 * @Description: 搜索旋转排序数组
 * @Author: guchen
 * @Date: 2020-11-25 15:02:49
 * @LastEditTime: 2020-11-25 15:08:52
 */
#include "../alg.h"
class Solution {
public:
    // 二分查找，关键是如何确定丢弃哪一半
    // 旋转后的数组一切为二，其中一半一定是有序的，另一半可能有序也可能部分有序; 可以通过判断每一边的左右两个端点来判断该边是否有序
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target == nums[mid]) return mid;
            // 注意这里是如何判断哪一边有序的，这里把mid包含在左半边了！避免不必要的细节问题！
            if (nums[l] <= nums[mid]) { // left is sorted
                if (target >= nums[l] && target <= nums[mid]) r = mid - 1;  // target is in right half
                else l = mid + 1;
            } else {    // right is sorted
                if (target >= nums[mid] && target <= nums[r]) l = mid + 1;  // target is in left half
                else r = mid - 1;
            }
        }
        return -1;
    }
};