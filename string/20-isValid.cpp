/*
 * @Description: 有效的括号
 * @Author: guchen
 * @Date: 2020-09-21 16:09:23
 * @LastEditTime: 2020-09-23 21:32:39
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    // 利用栈进行括号匹配 time: O(n) space: O(n)
    bool isValid(string s) {
        stack<char> st;
        pair<char, char> pairs[3] = {{'(',')'}, {'[',']'}, {'{','}'} };
        char c;
        for (int i = 0; i < s.size(); i++) {
            c = s[i];
            if (c == '{' || c == '(' || c == '[')
                st.push(c);
            else {
                if (st.empty())
                    return false;
                char top = st.top();
                for (int i = 0; i < 3; i++) {
                    if (pairs[i].second == c) {
                        if (pairs[i].first == top)
                            st.pop();
                        else
                            return false;
                    }
                }
            }
        }
        if (!st.empty())
            return false;
        return true;
    }
};