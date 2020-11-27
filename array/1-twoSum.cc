/*
 * @Description: 两数之和
 * @Author: guchen
 * @Date: 2020-09-16 12:50:00
 * @LastEditTime: 2020-11-27 22:52:48
 */
#include "../alg.h"

class Solution {
public:
    // time: O(n) space: O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            auto it = m.find(target - nums[i]);
            if (it == m.end()) m[nums[i]] = i;
            else return {it->second, i};
        }
        return {};
    }
};

class Solution {
public:
    // multimap unordered_multimap 都行，看内存消耗和查询效率
    // time: O(1) space: O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_multimap<int, int> m;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            auto itr = m.find(target - nums[i]);
            if (itr != m.end()) {
                ans = {(*itr).second, i};
                break;
            } else {
                // m.insert(pair<int, int>(nums[i], i));
                m.insert(make_pair(nums[i], i));
            }
        }
        return ans;
    }

    // direct solution 
    // time: O(n^2) space: O(1)
    vector<int> twoSum1(vector<int>& nums, int target) {
        int size = nums.size();
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {};
    }
    
    // multimap底层是红黑树
    // time: O(log(n)) space: O(n)
    vector<int> twoSum2(vector<int>& nums, int target) {
        multimap<int, int> m;
        vector<int> ans;
        // 这题需要用到下标，用迭代器比较繁琐，这是学习下迭代器的使用
        for (auto itr = nums.begin(); itr != nums.end() ; itr++) {
            int diff = target - *itr;
            auto m_itr = m.find(diff);
            int index = itr - nums.begin();
            if (m_itr != m.end()) {
                ans = {(*m_itr).second, index};
                break;
            } else {
                m.insert(pair<int, int>(*itr, index));
            }
        }
        for (auto n : m) {
            cout << n.first << ":" << n.second << endl;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    int n;
    int target;
    cin >> target;
    while (cin >> n)
        nums.push_back(n);
    cout << "target: " <<  target << endl;
    cout << "index: ";
    for (int i = 0; i < nums.size(); i++)
        cout << i << " ";
    cout << endl;
    cout << "nums: ";
    for (const auto& n : nums)
        cout << n << " ";
    cout << endl;
    vector<int> ans(s.twoSum(nums, target));
    cout << "ans: ";
    for (const auto& n : ans)
        cout << n << " ";
}