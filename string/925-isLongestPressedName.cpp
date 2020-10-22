/*
 * @Description: 长键按入
 * @Author: guchen
 * @Date: 2020-10-22 16:06:36
 * @LastEditTime: 2020-10-22 16:06:49
 */
#include "../alg.h"
class Solution {
public:
    // time: O(n+m) space: O(1)
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (j < typed.size()) {
            if (i < name.size() && typed[j] == name[i]) i++, j++;
            else if (j > 0 && typed[j] == typed[j - 1]) j++;
            else return false;
        }
        return i == name.size();
    }

    // 双指针 time: O(n+m) space: O(1)
    // - 从左到右依次统计name和typed连续相等字符的个数
    // - 如果name个数小于等于typed，说明是长键按入，否则false
    // - 只有当双指针同时到达name和typed的末尾，才表明是长键按入
    bool isLongPressedName1(string name, string typed) {
        if (typed.size() < name.size()) return false;
        int i = 0, j = 0;
        int ncnt, tcnt;
        char c;
        while (i < name.size() && j < typed.size()) {
            c = name[i];
            ncnt = 0, tcnt = 0;
            while (i < name.size() && name[i] == c) {
                ncnt++;
                i++;
            }
            while (j < typed.size() && typed[j] == c) {
                tcnt++;
                j++;
            }
            if (ncnt > tcnt) return false;
        }
        return i == name.size() && j == typed.size();
    }
};