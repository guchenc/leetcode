/*
 * @Description: K距离间隔重排字符串
 * @Author: guchen
 * @Date: 2020-11-30 16:30:44
 * @LastEditTime: 2020-11-30 16:51:25
 */
#include "../alg.h"

class Solution {
public:
    string rearrangeString(string& str, int k) {
        string res;
        unordered_map<char, int> count;
        int maxcnt = 0;
        for (auto c : str) {
            count[c]++;
            maxcnt = max(maxcnt, count[c]);
        }

        if ((maxcnt - 1) * k + maxcnt > str.size()) return "";

        auto cmp = [&](const char& c1, const char& c2) {
            return count[c1] < count[c2];
        };
        priority_queue<char, vector<char>, decltype(cmp)> pq(cmp);
        for (auto it = count.begin(); it != count.end(); it++)
            pq.push(it->first);

        int cnt = 0;
        while (!pq.empty()) {
            
        }
    }
};
