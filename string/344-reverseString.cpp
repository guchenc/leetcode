/*
 * @Description: 反转字符串
 * @Author: guchen
 * @Date: 2020-09-23 22:25:07
 * @LastEditTime: 2020-11-14 17:42:42
 */
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // 递归实现 time: O(n) space: O(n)
    void reverseString(vector<char>& s) {
        reverse(s, 0, s.size() - 1);
    }

    void reverse(vector<char>& s, int i, int j) {
        if (i >= j) return;
        swap(s[i], s[j]);
        reverse(s, i + 1, j - 1);
    }

    // time: O(n) space: O(1)
    void reverseString(vector<char>& s) {
        int len = s.size();
        if (len == 0 || len == 1)
            return;
        int l = 0, r = len - 1;
        while (l < r) {
            int temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            l++;
            r--;
        }
    }

};