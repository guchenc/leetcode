/*
 * @Description: 反转字符串
 * @Author: guchen
 * @Date: 2020-09-23 22:25:07
 * @LastEditTime: 2020-09-23 22:26:10
 */
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
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