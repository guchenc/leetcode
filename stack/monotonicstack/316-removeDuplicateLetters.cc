/*
 * @Description: 去除重复字母
 * @Author: guchen
 * @Date: 2020-12-02 11:34:33
 * @LastEditTime: 2020-12-02 12:39:43
 */
#include "../../alg.h"
class Solution {
public:
    // 思路同解法1 简洁写法 string也可以模仿栈，而不用vector<char>
    string removeDuplicateLetters(string s) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (res.find(s[i]) != string::npos) continue;
            while (!res.empty() && res.back() > s[i] && s.find(res.back(), i) != string::npos)
                res.pop_back();
            res.push_back(s[i]);
        }
        return res;
    }

    // 单调栈 用栈来存储最终返回的字符串，并维持字符串的最小字典序。
    // 每遇到一个字符，如果这个字符不存在于栈中，就需要将该字符压入栈中。但在压入之前，需要先将之后还会出现，并且字典序比当前字符小的栈顶字符移除，然后再将当前字符压入
    // time: O(n) space: O(n)
    string removeDuplicateLetters1(string s) {
        string res;
        if (s.empty()) return "";
        int left[26] = {0}; // 记录剩余元素个数
        bool placed[26] = {false};  // 记录当前元素是否位置已经被确定，即是否在栈中
        for (auto c : s) left[c - 'a']++;
        vector<char> ups;
        for (int i = 0; i < s.size(); i++) {
            // for (auto c : ups) cout << c << " ";
            // cout << endl;
            if (placed[s[i] - 'a']) {
                left[s[i] - 'a']--; // 该字符已经在栈中，不再处理，计数减一
                continue;
            } 
            while (!ups.empty() && ups.back() > s[i] && left[ups.back() - 'a'] > 0) {
                // left[ups.back() - 'a']--;   // 不需要减一，入的时候已经减过了
                placed[ups.back() - 'a'] = false;
                ups.pop_back();
            }
            ups.push_back(s[i]);
            left[s[i] - 'a']--;
            placed[s[i] - 'a'] = true;
        }
        for (auto c : ups) res += c;
        return res;
    }
};;

int main()
{
    Solution s;
    s.removeDuplicateLetters("edebbed");
}