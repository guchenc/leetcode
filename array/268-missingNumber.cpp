/*
 * @Description: 丢失的数字
 * @Author: guchen
 * @Date: 2020-10-28 21:04:33
 * @LastEditTime: 2020-10-28 21:04:44
 */
#include "../alg.h"
class Solution {
public:
    // 利用^的抵消性质
    // 1 ^ 5 = 5  5 ^ 5 = 1
    // 1 ^ 1 ^ 2 ^ 2 ^ 3 = 3
    // [3,0,1] 3 ^ 3 ^ 0 ^ 0 ^ 1 ^ 2 ^ 1 = 2
    int missingNumber(vector<int>& nums) {
        int n = nums.size(); // 从n开始执行异或运算，如果集合包含0-n-1 那么n就是缺失的那个
        for (int i = 0; i < nums.size(); i++) {
            n ^= nums[i];
            n ^= i;
        }
        return n;
    }
    // 思想很好!
    int missingNumber2(vector<int>& nums) {
         int n = nums.size();
         for (int i = 0; i < n; i++) {
             while (nums[i] < n && nums[i] != i)
                 swap(nums[i], nums[nums[i]]);
         }
        for (int i = 0; i < n; i++)
            if (nums[i] != i) return i;
        return n; 
    }

    // 直接将所有数相加会有溢出风险
    int missingNumber1(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return (n * n + n) / 2 - sum;
    }
    
};