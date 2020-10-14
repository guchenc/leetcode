/*
 * @Description: 反转字符串中的单词III
 * @Author: guchen
 * @Date: 2020-10-14 20:23:47
 * @LastEditTime: 2020-10-14 20:24:41
 */
#include <string>
using namespace std;

class Solution {
public:
    // 瞎写，不优雅
    string reverseWords(string s) {
        int i, begin = -1;
        for (i = 0; i < s.size(); i++) {
            if (begin == -1) {
                if (s[i] != ' ')
                begin = i;
                continue;    
            } else {
                if (s[i] == ' ') {
                    reverse_word(s, begin, i - 1);
                    begin = -1;
                }
            }
        }
        if (begin != -1) reverse_word(s, begin, i - 1);
        return s;
    }
    void reverse_word(string& s, int l , int r) {
        while (l < r) swap(s[l++], s[r--]);
    }
};