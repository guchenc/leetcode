/*
 * @Description: 验证回文串
 * @Author: guchen
 * @Date: 2020-10-10 17:40:23
 * @LastEditTime: 2020-10-10 17:41:08
 */
#include <string>
using namespace std;

class Solution {
public:
    // 双指针 time: O(n) space: O(1)
    bool isPalindrome(string s) {
        if (s.size() == 0) return true;
        // transform(s.begin(), s.end(), s.begin(), ::toupper);
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !isalnum(s[l])) l++;
            while (l < r && !isalnum(s[r])) r--;
            if (toupper(s[l]) != toupper(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};