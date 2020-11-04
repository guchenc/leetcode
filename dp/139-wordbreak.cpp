/*
 * @Description: 单词拆分
 * @Author: guchen
 * @Date: 2020-11-03 22:13:06
 * @LastEditTime: 2020-11-03 22:15:17
 */
#include "../alg.h"

class Solution {
public:
    // DP
    // dp[i]表示s[0..i - 1]能否被拆分成word，换句话说前i个字符能否分成word
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);   // 理解为何设置为s.size() + 1
        dp[0] = true;
        int i = 0;
        while (i <= s.size()) {
            if (dp[i]) {
                for (auto& w : wordDict) {
                    if (i + w.size() > s.size()) continue;
                    if (s.compare(i, w.size(), w) == 0) dp[i + w.size()] = true; // 这里i恰好从适当的位置开始
                }
            }
            i++;
        }
        // for (auto n : dp) cout << n << " ";
        // cout << endl;
        return dp[s.size()];
    }
    // DP
    // dp[i]表示s[0..i]能否被拆分成word
    bool wordBreak2(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size(), false);
        int i = 0;
        while (i < s.size()) {
            if (i == 0 || dp[i - 1]) {
                for (auto& w : wordDict) {
                    if (i + w.size() > s.size()) continue;
                    if (s.compare(i, w.size(), w) == 0) dp[i + w.size() - 1] = true;
                }
            } 
            i++;
        }
        // for (auto n : dp) cout << n << " ";
        // cout << endl;
        return dp[s.size() - 1];
    }

    int minlen = INT_MAX;
    int maxlen = INT_MIN;
    // 超时! time: O(?) space:O(?) 
    bool wordBreak1(string s, vector<string>& wordDict) {
        for (auto& w : wordDict) {
            // if (w.size() < minlen) minlen = w.size();    为啥这样会出错啊????
            // if (w.size() > maxlen) maxlen = w.size();

            // int len = w.size();   这样就行了
            // if (len < minlen) minlen = len;
            // if (len > maxlen) maxlen = len;
            int len = w.size();
            minlen = min(minlen, len);
            maxlen = max(maxlen, len);
        }
        if (minlen > s.size()) return false;
        return match(s, wordDict, 0);
    }

    bool match(string& s, vector<string>& wordDict, int begin) {
        if (begin == s.size()) return true;
        for (int len = minlen; len <= maxlen; len++) {
            for (auto& w : wordDict) {
                if (w.size() != len) continue;
                if (s.compare(begin, len, w, 0, len) == 0 && match(s, wordDict, begin + len))
                    return true;
            }
        }
        return false;
    }
};