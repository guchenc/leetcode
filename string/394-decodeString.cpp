/*
 * @Description: 字符串解码
 * @Author: guchen
 * @Date: 2020-10-05 23:50:37
 * @LastEditTime: 2020-10-05 23:51:24
 */
#include <stack>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    // 栈 time: O(n) space: O(n)
    string decodeString(string s) {
        stack<string> st;
        ostringstream oss(ostringstream::ate);
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                while (s[i] >= '0' && s[i] <= '9') {
                    cnt = cnt * 10 + (s[i] - '0');
                    i++;
                }
                i--;
            } else if (s[i] == '[') {
                st.push(oss.str());
                st.push(to_string(cnt));
                cnt = 0;
                oss.str("");
            } else if (s[i] == ']') {
                int n = stoi(st.top()); st.pop();
                string temp = st.top(); st.pop();
                while (n-- > 0) temp.append(oss.str());
                oss.str(temp);
            } else {
                oss << s[i];
            }
        }
        return oss.str();
        
    }

    // 不支持嵌套
    string decodeString1(string s) {
        ostringstream oss;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] > '0' && s[i] < '9') {
                int cnt = s[i] - '0';
                int len = 0;
                i += 2;
                int begin = i;
                while (s[i] != ']') {
                    len++;
                    i++;
                }
                string temp = s.substr(begin, len);
                while (cnt > 0) {
                    oss << temp;  
                    cnt--;
                }
            } else 
                oss << s[i];
        }
        return oss.str();
    }
};