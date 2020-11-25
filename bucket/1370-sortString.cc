/*
 * @Description: 上升下降字符串
 * @Author: guchen
 * @Date: 2020-11-25 15:15:49
 * @LastEditTime: 2020-11-25 15:16:14
 */
#include "../alg.h"
class Solution {
public:
    // 桶：由于输入字符串限定为26个英文小写字母，所以用大小为26的整型数组统计各字母出现频率，注意到在构造时我们只关注字符本身，而不关注字符在原字符串中的位置
    // time: O(|字符集|*|s|) space: O(|字符集|) 最坏情况下所有字符相同，每次找一个字符都需要遍历整个桶
    string sortString(string s) {
        string res;
        int alphabet[26] = {0};
        for (int i = 0; i < s.size(); i++) 
            alphabet[s[i] - 'a']++;
        int cnt = 0;
        while (cnt != s.size()) {
            for (int i = 0; i < 26;  i++) {
                if (alphabet[i] > 0) {
                    res += i + 'a';
                    alphabet[i]--;
                    cnt++;
                }
            }
            for (int i = 25; i >= 0;  i--) {
                if (alphabet[i] > 0) {
                    res += i + 'a';
                    alphabet[i]--;
                    cnt++;
                }
            }
        }
        return res;
    }

    // 憨憨解法，暴力模拟
    string sortString1(string s) {
        string res;
        if (s.size() == 0) return res;
        sort(s.begin(), s.end());
        int cnt = 0, size = s.size();
        char last;
        while (cnt != size) {
            int i;
            bool flag = false;
            for (i = 0; i < size; i++) {
                if (!flag && s[i] != '-') {
                    last = s[i];
                    s[i] = '-';
                    res += last;
                    cnt++;
                    flag = true;
                    continue;
                }
                if (s[i] != '-' && s[i] > last) {
                    last = s[i];
                    s[i] = '-';
                    res += last;
                    cnt++;
                }
            }
            flag = false;
            for (int i = size - 1; i >= 0; i--) {
                if (!flag && s[i] != '-') {
                    last = s[i];
                    s[i] = '-';
                    res += last;
                    cnt++;
                    flag = true;
                    continue;
                }
                if (s[i] != '-' && s[i] < last) {
                    last = s[i];
                    s[i] = '-';
                    res += last;
                    cnt++;
                }
            }
        }
        return res;
    }
};