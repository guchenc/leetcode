/*
 * @Description: 不同字符的最小子序列 同316
 * @Author: guchen
 * @Date: 2020-12-02 12:29:00
 * @LastEditTime: 2020-12-02 12:29:37
 */
#include "../alg.h"
class Solution {
public:
    string smallestSubsequence(string s) {
        string res;
        vector<char> ups;
        int left[26] = {0};
        bool placed[26] = {false};
        for (auto c : s) left[c - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            if (placed[s[i] - 'a']) {
                left[s[i] - 'a']--;
                continue;
            }
            while (!ups.empty() && ups.back() > s[i] && left[ups.back() - 'a'] > 0) {
                placed[ups.back() - 'a'] = false;
                ups.pop_back();
            }
            ups.push_back(s[i]);
            placed[s[i] - 'a'] = true;
            left[s[i] - 'a']--;
        }
        for (auto c : ups) res += c;
        return res;

    }
};