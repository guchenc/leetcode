/*
 * @Description: 全排列II
 * @Author: guchen
 * @Date: 2020-09-18 20:22:36
 * @LastEditTime: 2020-09-18 20:56:11
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
    // 改进，不使用set，先对nums排序，这样所有相同的数字排列在一起，之后通过条件判断保证重复数字序列最左端的数字会被选择用于放置
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used(len, false);

        if (len == 0)
            return ans;
        sort(nums.begin(), nums.end());
        dfs(nums, len, used, path, 0, ans);
        return ans;
    }
    
    void dfs(vector<int>& nums, int len, vector<bool> used, vector<int>& path, int depth, vector<vector<int>>& ans) {
        // print_unused(depth, nums, used);
        if (depth == len) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < len; i++) {
            if (used[i] || (i > 0 && nums[i] == nums[i - 1]) && !used[i - 1]) // 注意为何是!used[i-1]
                continue;
            // cout << "pick: " << nums[i] << endl;
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, len, used, path, depth + 1, ans);
            path.pop_back();
            used[i] = false;
        }
    }
    void dfs2(vector<int>& nums, int len, vector<bool> used, vector<int>& path, int depth, vector<vector<int>>& ans) {
        // print_unused(depth, nums, used);
        set<int> s; // 用set记录每个排列当前位置已经选用过数字
        if (depth == len) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < len; i++) {
            if (used[i])
                continue;
            // cout << "pick: " << nums[i] << endl;
            auto itr = s.find(nums[i]);
            if (itr != s.end())
                continue;
            s.insert(nums[i]);
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, len, used, path, depth + 1, ans);
            path.pop_back();
            used[i] = false;
        }
    }
};