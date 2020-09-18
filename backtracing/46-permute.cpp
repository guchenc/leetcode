/*
 * @Description: 全排列
 * @Author: guchen
 * @Date: 2020-09-18 20:20:49
 * @LastEditTime: 2020-09-18 20:21:46
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // dfs + 回溯 time: O(n*n!) space: O(n*n!)
    // 回溯算法的时间复杂度是指数级别的，本质上是一种遍历的算法
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used(len, false);

        if (len == 0)
            return ans;
        
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
            if (used[i])
                continue;
            // cout << "pick: " << nums[i] << endl;
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, len, used, path, depth + 1, ans);
            path.pop_back();
            used[i] = false;
        }
    }

    void print_unused(int depth, vector<int>& nums, vector<bool> used) {
        cout << "depth: " << depth << " unused: [";
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == false)
                cout << nums[i] << " ";
        }
        cout << "]" << endl;
    }
    
};
