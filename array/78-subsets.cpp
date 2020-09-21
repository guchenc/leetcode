/*
 * @Description: 
 * @Author: guchen
 * @Date: 2020-09-20 18:22:43
 * @LastEditTime: 2020-09-21 00:21:04
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // 最优解法 time: O(n^2) space: O(1)
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        sort(nums.begin(), nums.end()); // 排序 O(nlogn)
        if (len < 3)
            return res;
        for (int i = 0; i < len - 2 && nums[i] <= 0; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            twoSum(res, nums, i + 1, len - 1, -nums[i]);
        }
        return res;
    }
    
    void twoSum(vector<vector<int>>& res, vector<int>& nums, int start, int end, int target) {
        int sum;
        while (start < end) {
            sum = nums[start] + nums[end];
            if (sum > target) {
                end--;
            } else if (sum < target) {
                start++;
            } else {
                res.push_back({-target, nums[start], nums[end]});
                while (start < end && nums[start] == nums[start + 1])
                    start++;
                start++;
                while (start < end && nums[end] == nums[end - 1])
                    end--;
                end--;
            }
        }
    }

    // 暴力解法(超时)) time: O(n^3) space: O(n)
    vector<vector<int>> threeSum2(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        if (len < 3)
            return res;
        vector<bool> visited(len, false);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++) {
            if (i > 0 && !visited[i - 1] && nums[i] == nums[i - 1])
                continue;
            visited[i] = true;
            for (int j = i + 1; j < len; j++) {
                if (j > 0 && !visited[j - 1] && nums[j] == nums[j - 1])
                    continue;
                visited[j] = true;
                for(int k = j + 1; k < len; k++) {
                    if (k > 0 && !visited[k - 1] && nums[k] == nums[k - 1])
                        continue;
                    visited[k] = true;
                    if (nums[i] + nums[j] + nums[k] == 0)
                        res.push_back({nums[i], nums[j], nums[k]});
                    visited[k] = false;
                }
                visited[j] = false;
            }
            visited[i] = false;
        }
        return res;
    }

    // // 不正确的憨憨解法
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     vector<vector<int>> res;
    //     unordered_multimap<int, pair<int,int>> m;
    //     sort(nums.begin(), nums.end());
    //     int len = nums.size();
    //     int mid;
    //     if (len < 3)
    //         return res;
    //     for (int i = 0; i < len; i++) {
    //         if (nums[i] <= 0 && nums[i + 1] > 0)
    //             mid = i;
    //         for (int j = i + 1; j < len; j++) {
    //             m.insert(make_pair(nums[i] + nums[j], make_pair(i, j)));
    //         }
    //     }
    //     for (int i = 0; i < mid; i++) {
    //         if (i > 0 && nums[i] == nums[i - 1])
    //             continue;
    //         auto range = m.equal_range(-nums[i]);
    //         for (auto it = range.first; it != range.second; it++) {
    //             if (i == it->second.first || i == it->second.second)
    //                 continue;
    //             res.push_back({nums[i], nums[it->second.first], nums[it->second.second]});
    //         }
    //     }
    //     return res;
    // }

    // DFS+回溯(超时) time: O(n^3) space: O(n)
    vector<vector<int>> threeSum1(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        int len = nums.size();
        if (nums.size() < 3)
            return res;
        vector<bool> visited(len, false);
        sort(nums.begin(), nums.end());
        dfs(res, ans, nums, len, visited, 0, -1,0);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& ans, vector<int>& nums, int len, vector<bool>& visited, int pos, int begin, int sum) {
        if (pos == 3) {
            if (sum == 0) res.push_back(ans);
            return;
        } 
        for (int i = begin + 1; i < len; i++) {
            if (!visited[i]) {
                if (i > 0 && visited[i - 1] == false && nums[i] == nums[i - 1])
                    continue;
                visited[i] = true;
                ans.push_back(nums[i]);
                dfs(res, ans, nums, len, visited, pos + 1, i, sum + nums[i]);
                ans.pop_back();
                visited[i] = false;
            }
        }
        return ;
    }
};