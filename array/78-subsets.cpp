/*
 * @Description: 子集
 * @Author: guchen
 * @Date: 2020-09-20 18:22:43
 * @LastEditTime: 2020-11-03 20:29:54
 */
#include "../alg.h"
class Solution {
public:
    // 遍历一遍数组，将当前元素添加到结果集中的已知子集构成新的子集
    // time: O(n*n^2) space: O(n)
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for (int i = 0; i < nums.size(); i++) {
            int size = res.size();
            for (int j = 0; j < size; j++) {
                vector<int> tmp(res[j]);
                tmp.emplace_back(nums[i]);
                res.emplace_back(tmp);
            }
        }
        return res;
    }
    vector<vector<int>> subsets1(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        generate(nums, res, ans, 0);
        return res;
    }

    void generate(vector<int>& nums, vector<vector<int>>& res, vector<int>& ans, int idx) {
        res.push_back(ans);
        if (idx == nums.size()) return;
        for (int i = idx; i < nums.size(); i++) {
            ans.push_back(nums[i]);
            generate(nums, res, ans, i + 1);
            ans.pop_back();
        }
    }
};