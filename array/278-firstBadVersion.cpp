/*
 * @Description: 第一个错误的版本
 * @Author: guchen
 * @Date: 2020-10-22 15:57:47
 * @LastEditTime: 2020-10-22 15:58:11
 */
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
bool isBadVersion(int n);
class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, m;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (isBadVersion(m)) {
                if (m == 1) return m;
                if (m - 1 >= 1 && !isBadVersion(m - 1)) return m;
                r = m - 1;
            } else {
                if (m + 1 <= n && isBadVersion(m + 1)) return m + 1;
                l = m + 1;
            }
        }
        return -1;
    }
};