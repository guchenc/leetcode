/*
 * @Description: 翻转字符串里的单词
 * @Author: guchen
 * @Date: 2020-10-12 09:45:35
 * @LastEditTime: 2020-10-18 15:18:32
 */
#include "../alg.h"

class Solution {
public:
    // 先反转整个字符串，再反转每个单词
    string reverseWords(string s) {
        int l = 0, r = 0;
        for (int i = 0; i < s.size(); i++) {    // 统计左边空格数
            if (s[i] != ' ') break;
            l++;
        }
        for (int i = s.size() - 1; i >= 0; i--) { // 统计右边空格数
            if (s[i] != ' ') break;
            r++;
        }
        string res(s.rbegin() + r, s.rend() - l);   // 构造res，删除两端空格并reverse
        l = -1, r = -1;
        for (int i = 0; i < res.size(); i++) {
            if (l == -1) {
                if (res[i] == ' ') continue;
                l = i;
            } 
            if ((i + 1 < res.size() && res[i + 1] == ' ') || i + 1 == res.size()) {
                r = i;
                while (l <= r) swap(res[l++], res[r--]);
                l = -1;
            }
        }
        return res;
    }
    // 不推荐的做法 
    string reverseWords1(string s) {
        stack<string> st;
        istringstream iss(s);
        string res, word;
        while (getline(iss, word, ' ')) 
            if (word != "") st.push(word);
        while (!st.empty()) {
            res += st.top();
            st.pop();
            if (!st.empty()) res += " ";
        }
        return res;
    }
    // 栈
    string reverseWords(string s) {
        stack<pair<int, int>> st;
        string res;
        int i = 0, start;
        while (i < s.size()) {
            if (s[i] != ' ') {
                start = i;
                while (i < s.size() && s[i] != ' ') i++;
                st.push({start, i - start});
            } else i++;
        }
        while (!st.empty()) {
            auto w = st.top(); st.pop();
            res.append(s, w.first, w.second);
            if (!st.empty()) res += " ";
        }
        return res;
    }
};