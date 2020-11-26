/*
 * @Description: 第一个错误的版本
 * @Author: guchen
 * @Date: 2020-11-26 20:24:21
 * @LastEditTime: 2020-11-26 20:24:36
 */
bool isBadVersion(int version);
class Solution {
public:
    // 利用了模板II
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (isBadVersion(m)) r = m;
            else l = m + 1;
        }
        return l;
    }
};