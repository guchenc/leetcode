/*
 * @Description: 字符串中的第一唯一字符
 * @Author: guchen
 * @Date: 2020-10-22 16:04:19
 * @LastEditTime: 2020-10-22 16:04:33
 */
#include "../alg.h"
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) == m.end()) m[s[i]] = 1;
            else m[s[i]] += 1;
        }
        for (int i = 0; i < s.size(); i++)
            if (m[s[i]] == 1) return i;
        return -1;
    }
    // 遍历两遍字符串 time: O(n) space: O(n)
    // - 第一遍统计各字符第一次出现的位置以及个数
    // - 第二遍返回最先出现的个数为1的字符
    int firstUniqChar1(string s) {
        unordered_map<char, pair<int, int>> m;
        int i;
        for ( i = 0; i < s.size(); i++) {
            if (m.find(s[i]) == m.end()) m[s[i]] = {i, 1};
            else m[s[i]].second++;
        }
        for (int i = 0; i < s.size(); i++)
            if (m[s[i]].second == 1) return m[s[i]].first;
        return -1;
    }
};