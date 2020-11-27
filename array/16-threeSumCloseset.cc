/*
 * @Description: 最接近的三数之和
 * @Author: guchen
 * @Date: 2020-11-27 22:45:32
 * @LastEditTime: 2020-11-27 22:46:52
 */
#include "../alg.h"
class Solution {
public:
    // time: O(n^2) space: O(nlogn)
    int threeSumClosest(vector<int>& nums, int target) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < N - 2; i++) {
            int l = i + 1, r = N - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < abs(closest - target)) closest = sum;
                if (sum > target) r--;
                else if (sum < target) l++;
                else return target;
            }
        }
        return closest;
    }

    int threeSumClosest1(vector<int>& nums, int target) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < N - 2; i++) {
            int l = i + 1, r = N - 1;
            while (l < r) {
                int twosum = nums[l] + nums[r];
                if (abs(nums[i] + twosum - target) < abs(closest - target)) closest = nums[i] + twosum;
                if (twosum + nums[i] > target) r--;
                else if (twosum + nums[i] < target) l++;
                else return target;
            }
        }
        return closest;
    }
};