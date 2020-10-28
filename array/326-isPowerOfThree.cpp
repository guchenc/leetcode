/*
 * @Description: 3的幂
 * @Author: guchen
 * @Date: 2020-10-28 20:56:00
 * @LastEditTime: 2020-10-28 20:56:12
 */
#include "../alg.h"
class Solution {
public:
    int romanToInt(string s) {
        int res = 0, i;
        unordered_map<char, int> val = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (i = 0; i < s.size() - 1; i++) {
            if (val[s[i]] >= val[s[i + 1]]) {
                res += val[s[i]];
            } else {
                res += val[s[i + 1]] - val[s[i]];
                i++;
            }
        }
        res += val[s[i]];
        return res;
    }
    int romanToInt1(string s) {
        int res = 0;
        unordered_map<char, int> val = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            switch (c) {
                case 'I':
                    if (i + 1 < s.size() && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                        res += val[s[i + 1]] - val[c];
                        i++;
                    } else res += val[c];
                    break;
                case 'X':
                    if (i + 1 < s.size() && s[i + 1] == 'L' || s[i + 1] == 'C') {
                        res += val[s[i + 1]] - val[c];
                        i++;
                    } else res += val[c];
                    break;
                case 'C':
                    if (i + 1 < s.size() && s[i + 1] == 'D' || s[i + 1] == 'M') {
                        res += val[s[i + 1]] - val[c];
                        i++;
                    } else res += val[c];
                    break;
                default: res += val[c];
            }
        }
        return res;
    }
};