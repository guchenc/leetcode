/*
 * @Description: 
 * @Author: guchen
 * @Date: 2020-10-11 19:15:08
 * @LastEditTime: 2020-10-11 19:15:30
 */
#include <vector>
using namespace std;
class Solution {
public:
    // 二分查找 time: O(logn) space: O(1)
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] > target) r = mid - 1;
            else if (nums[mid] < target) l = mid + 1;
            else return mid;
        }
        return l;
    }
};