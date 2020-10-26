/*
 * @Description: 有多少小于当前数字的数字
 * @Author: guchen
 * @Date: 2020-10-26 16:00:13
 * @LastEditTime: 2020-10-26 16:00:25
 */
#include "../alg.h"
class Solution {
public:
    // 桶思想 time: O(n) space: O(1)
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int bucket[101] = {0};
        int maxn = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            bucket[nums[i]] += 1;
            maxn = max(maxn, nums[i]);
        }
        int cnt = 0;
        for (int i = 0; i < maxn + 1; i++) {
            cnt += bucket[i];
            bucket[i] = cnt - bucket[i];
        }
        // for (int i = 0; i < maxn + 1; i++) cout << bucket[i] << " ";
        // cout << endl;
        for (int i = 0; i < nums.size(); i++)
            nums[i] = bucket[nums[i]];
        return nums;
    }
    // 排序后遍历一遍数组，将小于某个数的个数插入哈希表
    vector<int> smallerNumbersThanCurrent1(vector<int>& nums) {
        vector<int> res(nums);
        unordered_map<int, int>  m;
        sort(nums.begin(), nums.end());
        m[nums[0]] = 0;
        for (int i = 1; i < nums.size(); i++) 
            if (nums[i] > nums[i - 1]) m[nums[i]] = i;
        for (int i = 0; i < res.size(); i++)
            res[i] = m[res[i]];
        return res;
    }
};