/*
 * @Description: 左旋转字符串
 * @Author: guchen
 * @Date: 2020-12-03 15:45:31
 * @LastEditTime: 2020-12-03 15:45:51
 */
#include "../alg.h"
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int len = s.size();
        if (n == len) return s;
        for (int i = 0; i < n; i++) // append after s
            s += s[i];
        return s.substr(n, len); // return sub str
    }
};