/*
 * @Description: 翻转字符串里的单词
 * @Author: guchen
 * @Date: 2020-10-12 09:45:35
 * @LastEditTime: 2020-10-12 09:46:02
 */
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
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