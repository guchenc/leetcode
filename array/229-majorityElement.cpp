/*
 * @Description: 求众数II
 * @Author: guchen
 * @Date: 2020-11-09 17:30:08
 * @LastEditTime: 2020-11-09 17:30:20
 */
#include "../alg.h"
class Solution {
public:
    // 摩尔投票法  time: O(n) space: O(1)
    // 至多有两个数出现次数超过n/3
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if (nums.empty()) return res;
        int cnt0 = 0, cnt1 = 0;
        int cand0 = nums[0], cand1 = nums[0];
        for (auto& n : nums) {
            if (n == cand0) cnt0++;
            else if (n == cand1) cnt1++;
            else if (cnt0 == 0) { // 重置候选人0
                cand0 = n;
                cnt0++;
            } else if (cnt1 == 0) { // 重置候选人1
                cand1 = n;
                cnt1++;
            } else {
                cnt0--; // 两个候选人都要抵消
                cnt1--;
            }
        }
        // 最后剩下来的两个候选人是持有票前2多的
        cnt0 = 0;
        cnt1 = 0;
        for (auto n : nums) {
            if (n == cand0) cnt0++;
            if (n == cand1) cnt1++;
        }
        if (cnt0 > nums.size() / 3)  res.push_back(cand0);
        if (cand1 != cand0 && cnt1 > nums.size() / 3) res.push_back(cand1);
        return res;
    }
};