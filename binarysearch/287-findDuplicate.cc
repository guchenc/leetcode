/*
 * @Description: 寻找重复数
 * @Author: guchen
 * @Date: 2020-12-03 15:33:51
 * @LastEditTime: 2020-12-03 15:34:47
 */
#include "../alg.h"
class Solution {
public:
    // 类似解法2 二分思路是通过循环不断缩减区间
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;
        int res = -1;
        while (l < r) {
            int m = l + (r - l) / 2;
            int cnt = 0;
            for (auto n : nums)
                if (n <= m) cnt++;
            if (cnt <= m) l = m + 1;
            else r = m;
        }
        // 当l==r时，[l,r]只有一个元素，对于本题一定是结果
        return l;
    }

    // 思路类似1，但是使用二分，同时避免额外空间，二分思路是在循环内部不断更新结果，向左逼近
    // time: O(nlogn) space: O(1)
    int findDuplicate2(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;
        int res = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int cnt = 0;
            for (auto n : nums) // 统计小于等于m的个数
                cnt += n <= m;
            if (cnt > m) {
                res = m;    // 当前cnt > m，m可能是结果，记录到res中，随着二分动态更新，res逐渐逼近左侧
                r = m - 1;  // 这里若写成r = m会陷入死循环
            } else l = m + 1;
        }
        return res;
    }

    // 任意i属于[1, n]，计算小于等于i的元素的个数x，第一个x大于i的元素就是重复元素
    // time: O(n) space: O(n)
    int findDuplicate1(vector<int>& nums) {
        vector<int> count(nums.size(), 0);
        for (auto n : nums)
            count[n]++;
        for (int i = 1; i < nums.size(); i++) {
            count[i] = count[i] + count[i - 1];
            if (count[i] > i) return i;
        }
        return -1;
    }
};