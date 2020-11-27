/*
 * @Description: 四数之和
 * @Author: guchen
 * @Date: 2020-10-05 20:52:40
 * @LastEditTime: 2020-11-27 22:43:45
 */
#include "../alg.h"

class Solution {
public:
    // 关键点：先排序，之后按照四元组元素非递减查找所有满足条件的解，先确定第一个元素，再确定第二个元素，再确定剩下两个元素
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int N = nums.size();
        if (N < 4) return res;
        sort(nums.begin(), nums.end()); // 方便加速查找与降重
        for (int i = 0; i < N - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // 选取连续相等序列的第一个元素作为第一个数字
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) continue;   // 减枝
            if (nums[i] + nums[N - 1] + nums[N - 2] + nums[N - 3] < target) continue;   // 减枝
            for (int j = i + 1; j < N - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // 选取连续相等序列的第一个元素作为第二个数字
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) continue;   // 减枝
                if (nums[i] + nums[j] + nums[N - 1] + nums[N - 2] < target) continue;   // 减枝
                int l = j + 1, r = N - 1;
                while (l < r) {
                    int twoSum = nums[l] + nums[r];
                    if (nums[i] + nums[j] + twoSum > target) r--;
                    else if (nums[i] + nums[j] + twoSum < target) l++;
                    else {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l + 1 < r && nums[l] == nums[l + 1]) l++;
                        l++;
                        while (r - 1 > l && nums[r] == nums[r - 1]) r--;
                        r--;
                    }
                }
            }
        }
        return res;
    }
};

class Solution {
public:

    // 排序+双指针+减枝 time: O(n^3) space: ?
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int size = nums.size();
        if (size < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 3; i++) {    // 注意size - 3
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) continue;   // 减枝
            if (nums[i] + nums[size - 3] + nums[size - 2] + nums[size - 1] < target) continue;  // 减枝
            for (int j = i + 1; j < size - 2; j++) {    // 注意size - 2
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) continue;   // 减枝
                if (nums[i] + nums[j] + nums[size - 2] + nums[size - 1] < target) continue; // 减枝
                int left = j + 1, right = size - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum > target) {
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        right--;
                    }
                }
            }
        }
        return res;
    }

    vector<vector<int>> res;
    vector<int> ans;
    int size;
    // DFS+回溯 超时如何减枝? 
    vector<vector<int>> fourSum1(vector<int>& nums, int target) {
        size = nums.size();
        if (size < 4) return res;
        sort(nums.begin(), nums.end());
        dfs(nums, target, 0, 0, 0);
        return res;
    }

    void dfs(vector<int>& nums, int target, int sum, int pos, int cnt) {
        if (pos > size) return;
        if (cnt == 0 && pos == size - 3) return;
        if (cnt == 4) {
            // for (auto it = ans.begin(); it != ans.end(); it++)
            //     cout << *it << " ";
            // cout << endl;
            if (sum == target) res.push_back(ans);
            return;
        }
        for (int i = pos; i < size; i++) {
            if (i > pos && nums[i] == nums[i - 1]) continue;
            if (sum > 0 && nums[pos] > 0 && target < 0) break;
            // cout << "total: " << sum + nums[i] << " next: " << i + 1 << " cnt: " << cnt + 1 << endl;
            ans.push_back(nums[i]);
            dfs(nums, target, sum + nums[i], i + 1, cnt + 1);
            ans.pop_back();
        }
    }
};