/*
 * @Description: 前K个高频元素
 * @Author: guchen
 * @Date: 2020-11-03 20:26:12
 * @LastEditTime: 2020-11-03 20:26:42
 */
#include "../alg.h"

bool freqless(pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second;
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            auto it = m.find(nums[i]);
            if (it == m.end()) m[nums[i]] = 1;
            else it->second += 1;
        }
        vector<pair<int, int>> freq(m.begin(), m.end());
        sort(freq.begin(), freq.end(), freqless);
        vector<int> res;
        for (int i = 0; i < k; i++)
            res.push_back(freq[i].first);
        return res;
    }
};