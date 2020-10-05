/*
 * @Description: 三数之和
 * @Author: guchen
 * @Date: 2020-10-05 19:17:49
 * @LastEditTime: 2020-10-05 19:52:25
 */
#include <algorithm>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> ans;
    int size;

    // 利用双指针求两数之和
    vector<vector<int>> threeSum(vector<int>& nums) {
        size = nums.size();
        if (size < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            findTwoSum(nums, i + 1, size - 1, -nums[i]);
        }
        return res;
    }

    void findTwoSum(vector<int>& nums, int left, int right, int target) {
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum > target) {
                right--;
            } else if (sum < target) {
                left++;
            } else {
                res.push_back({-target, nums[left], nums[right]});
                while (left < right && nums[left + 1] == nums[left])
                    left++;
                left++;
                while (left < right && nums[right - 1] == nums[right])
                    right--;
                right--;
            }
        }
    }

    // DFS+回溯 超时 如何减枝?
    vector<vector<int>> threeSum1(vector<int>& nums) {
        size = nums.size();
        if (size < 3) return res;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, 0, 0);
        return res;
    }

    void dfs(vector<int>& nums, int sum, int pos, int cnt) {
        if (cnt == 3) {
            if (sum == 0) res.push_back(ans);
            return;
        }
        for (int i = pos; i < size; i++) {
            if (i > pos && nums[i] == nums[i - 1]) continue;
            ans.push_back(nums[i]);
            dfs(nums, sum + nums[i], i + 1, cnt + 1);
            ans.pop_back();
        }
    }
};

int main() {
    vector<int> nums;
    string input;
    string num;
    getline(cin, input);
    istringstream iss(input.substr(1, input.size() - 2));
    while (getline(iss, num, ','))
        nums.push_back(stoi(num));
    Solution s;
    vector<vector<int>> res = s.threeSum(nums);
    ostringstream oss;
    for (int i = 0; i < res.size(); i++) {
        oss << "[";
        for (int j = 0; j < res[i].size(); j++) {
            oss << res[i][j];
            if (j < res[i].size() - 1)
                oss << ",";
        }
        oss << "]";
        oss << endl;
    }
    cout << oss.str();
}