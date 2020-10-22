/*
 * @Description: 最长公共前缀
 * @Author: guchen
 * @Date: 2020-09-19 17:06:03
 * @LastEditTime: 2020-10-22 16:00:23
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    // 将字符串数组看作二维char数组，逐列进行比较，当某行到尾或者某行相应列不匹配结束
    // time: O(minlen * n) minlen为字符串数组中最短的字符串长度，n为字符串数组大小 space: O(1)
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        int nrow = strs.size();
        int ncol = strs[0].size();
        for (int j = 0; j < ncol; j++) {
            for (int i = 0; i < nrow; i++) {
                char c =strs[0][j];
                if (j == strs[i].size() || strs[i][j] != c)
                    return strs[0].substr(0, j);
            }
        }
        return strs[0];
    }
    // time: O(minlen * n) minlen为字符串数组中最短的字符串长度，n为字符串数组大小 space: O(1)
    string longestCommonPrefix2(vector<string>& strs) {
        char cur;
        int index = 0;
        int minlen = INT_MAX;
        
        if (strs.empty())
            return "";  
        for (auto s : strs) {
            if (s.empty()) return "";   // 存在空字符串，直接返回前缀""
            if (s.size() < minlen)  // 若无空字符串，记录最短字符串长度
                minlen = s.size();
        }

        while (index < minlen) {
            cur = strs[0][index];   // 每次取第一个字符串的相应位置进行比较
            for (auto s : strs) {
                if (s[index] != cur)    // 存在string相应位置不同，返回已确定的prefix
                    return strs[0].substr(0, index);
            }
            index++;
        } // 表明最短的非空字符串就是公共前缀
        return strs[0].substr(0, index);
    }
};