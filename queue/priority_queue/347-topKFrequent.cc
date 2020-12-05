/*
 * @Description: 前K个高频元素
 * @Author: guchen
 * @Date: 2020-12-04 14:20:56
 * @LastEditTime: 2020-12-04 14:21:13
 */
#include "../alg.h"
class Solution {
public:
    // 优先队列
    vector<int> topKFrequent1(vector<int>& nums, int k) {
        vector<int> res;
        auto cmp = [](const pair<int, int>& u, const pair<int, int>& v) {
            return u.second < v.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        unordered_map<int, int> count;
        for (auto n : nums)
            count[n]++;
        for (auto it = count.begin(); it != count.end(); it++)
            pq.push({it->first, it->second});
        while (k-- > 0) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> count;
        for (auto n : nums)
            count[n]++;
        for (auto n : count)    // 哈希表也可以使用增强for
            res.push_back(n.first);
        sort(res.begin(), res.end(), [&count](const int n1, const int n2) {
            return count[n1] > count[n2];
        });
        return vector<int>(res.begin(), res.begin() + k);
    }
};