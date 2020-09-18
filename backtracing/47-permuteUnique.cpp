/*
 * @Description: ȫ����II
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
    // �Ľ�����ʹ��set���ȶ�nums��������������ͬ������������һ��֮��ͨ�������жϱ�֤�ظ�������������˵����ֻᱻѡ�����ڷ���
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
            if (used[i] || (i > 0 && nums[i] == nums[i - 1]) && !used[i - 1]) // ע��Ϊ����!used[i-1]
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
        set<int> s; // ��set��¼ÿ�����е�ǰλ���Ѿ�ѡ�ù�����
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