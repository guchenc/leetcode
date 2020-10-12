/*
 * @Description: 实现strStr() 字符串匹配
 * @Author: guchen
 * @Date: 2020-10-12 10:54:42
 * @LastEditTime: 2020-10-12 10:55:04
 */
#include <string>
using namespace std;

class Solution {
public:
    // 暴力解法 time: O(mn) space: O(1)
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (m < n) return -1;
        bool match;
        for (int i = 0; i < m - n + 1; i++) {
            // cout << haystack.substr(i, m - i) << endl;
            match = true;
            for (int j = 0; j < needle.size(); j++) {
                if (haystack[i + j] != needle[j]) {
                    match = false;
                    break;
                } 
            }
            if (match) return i;
        }
        return -1;
    }
};