/*
 * @Description: 
 * @Author: guchen
 * @Date: 2020-09-20 18:22:43
 * @LastEditTime: 2020-09-20 19:45:56
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // DFS+回溯 time: O(n * 2^n) space: O(n)
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        int len = nums.size();
        dfs(res, ans, nums, len, 0);
        return res;
    }

    vector<vector<int>> subsets1(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        int len = nums.size();
        vector<bool> visited(len, false);
        dfs1(res, ans, nums, visited, len, 0);
        return res;
    }

    // 递归法实现子集枚举的通用解法 time: O(n * 2^n) space: O(n)
    void dfs(vector<vector<int>>& res, vector<int>& ans, vector<int>& nums, int len, int cur) {
        if (cur == len) {
            res.push_back(ans);
            return;
        }
        // 考虑选择当前位置
        ans.push_back(nums[cur]);
        dfs(res, ans, nums, len, cur + 1);
        ans.pop_back();
        // 考虑不选择当前位置
        dfs(res, ans, nums, len, cur + 1);
    }
    
    // DFS+回溯 time: O() space: O(n)
    void dfs1(vector<vector<int>>& res, vector<int>& ans, vector<int>& nums, vector<bool>& visited, int len, int level) {
        if (level == len)  return;
        for (int i = 0; i < len; i++) {
            if (!visited[i] && (ans.empty() || nums[i] > ans.back())) { // 进行剪枝避免重复
                visited[i] = true;
                ans.push_back(nums[i]);
                res.push_back(ans);
                dfs1(res, ans, nums, visited, len, level + 1);
                ans.pop_back();
                visited[i] = false;
            }
        }
    }
};