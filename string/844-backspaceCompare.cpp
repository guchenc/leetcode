/*
 * @Description: 比较含退格的字符串
 * @Author: guchen
 * @Date: 2020-10-19 13:28:48
 * @LastEditTime: 2020-10-19 13:29:01
 */
#include "../alg.h"

class Solution {
public:

    // 将S看作编辑器缓冲区，用pos指代光标位置，遍历字符串将字符放在光标指示处
    // time: O(n + m) space: O(1)
    bool backspaceCompare(string S, string T) {
        int spos = process(S);
        int tpos = process(T);
        if (spos != tpos) return false;
        for (int i = 0; i < spos; i++)
            if (S[i] != T[i]) return false;
        return true;
    }

    int process(string& s) {
        int pos = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) s[pos++] = s[i];
            if (s[i] == '#' && pos > 0) pos--;
        }
        return pos;
    }

    // 栈(编辑器是用栈实现的) time: O(n + m) space: O(n + m)
    bool backspaceCompare1(string S, string T) {
        return buildstring(S) == buildstring(T);
    }
    string buildstring(string& s) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) res.push_back(s[i]);
            if (s[i] == '#') if (!res.empty()) res.pop_back();
        }
        return res;
    }
};