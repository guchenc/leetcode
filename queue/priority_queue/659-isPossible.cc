/*
 * @Description: 分割数组为连续子序列
 * @Author: guchen
 * @Date: 2020-12-04 13:51:06
 * @LastEditTime: 2020-12-04 13:56:18
 */
#include "../../alg.h"
class Solution {
public:
    // 最优解 哈希表+贪心 time: O(n) space: O(n)
    // 缺点是无法知道分割后的子序列，是否可以通过添加额外信息获得?
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> countMap;   // 存储数组中的每个数字的剩余次数
        unordered_map<int, int> endMap;     // 存储数组中的每个数字作为结尾的子序列的数量。
        for (auto n : nums)
            countMap[n]++;
        for (auto n : nums) {
            if (countMap[n] == 0) continue;
            if (endMap.find(n - 1) != endMap.end() && endMap[n - 1] > 0) {
                endMap[n - 1]--;
                endMap[n]++;
                countMap[n]--;
            } else {
                // 为了保证子序列长度至少为3,当新建一个子序列时尝试一次构造长度为3的子序列，若无法构造则表明无法完成分割
                if (countMap.find(n + 1) == countMap.end() || countMap.find(n + 2) == countMap.end() || countMap[n + 1] == 0 || countMap[n + 2] == 0) return false;
                countMap[n]--;
                countMap[n + 1]--;
                countMap[n + 2]--;
                endMap[n + 2]++;
            }
        }
        return true;
    }

    // 同解法2 精简版 并且不调用erase
    bool isPossible3(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        for (auto& n : nums) {
            if (mp.find(n) == mp.end()) mp[n] = priority_queue<int, vector<int>, greater<int>>();
            auto it = mp.find(n - 1);
            if (it != mp.end() && !it->second.empty()) {
                int minlen = it->second.top(); it->second.pop();
                mp[n].push(minlen + 1);
            } else {
                mp[n].push(1);
            }
        }

        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second.empty()) continue;
            int minlen = it->second.top();
            if (minlen < 3) return false;
        }
        return true;
    }

    // 哈希表+最小堆  time: O(nlogn) space: O(n)
    // 由于需要将数组分割成一个或多个由连续整数组成的子序列，因此只要知道子序列的最后一个数字和子序列的长度，就能确定子序列。
    // 哈希表的键为子序列的最后一个数字，值为最小堆，用于存储所有的子序列长度，最小堆满足堆顶的元素是最小的，因此堆顶的元素即为最小的子序列长度。
    bool isPossible2(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) == mp.end())
                mp[nums[i]] = priority_queue<int, vector<int>, greater<int>>();
            auto it = mp.find(nums[i] - 1);
            if (it == mp.end()) {
                mp[nums[i]].push(1);
            } else {
                int minlen = it->second.top();
                it->second.pop();
                if (it->second.empty()) mp.erase(it->first);
                mp[nums[i]].push(minlen + 1);
            }
        }

        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second.top() < 3) return false;
        }
        return true;
    }

    // 错误思路
    bool isPossible1(vector<int>& nums) {
        int N = nums.size();
        if (N < 3) return false;
        unordered_map<int, int> count;
        for (auto n : nums)
            count[n] += 1;
        // for (auto n : count) cout << n.first << ":" << n.second << endl;
        for (int i = 0; i < N; i++) {
            int cur = nums[i];
            if (count[cur] == 0) continue;
            count[cur]--;
            int len = 1;
            while (1) {
                cur++;
                auto it = count.find(cur);
                if (it == count.end() || it->second == 0) break;
                count[cur]--;
                len++;
            }
            if (len < 3) return false;
        }
        return true;
    }
};