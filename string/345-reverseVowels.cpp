/*
 * @Description: 反转字符串中的原音字母
 * @Author: guchen
 * @Date: 2020-10-10 18:00:12
 * @LastEditTime: 2020-10-10 18:00:31
 */
#include <string>
using namespace std;

class Solution {
public:
    // 双指针 time: O(n) space: O(1)
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        string str = "aeiouAEIOU";
        while (l < r) {
            while (l < r && str.find(s[l]) == std::string::npos) l++;
            while (l < r && str.find(s[r]) == std::string::npos) r--;
            swap(s[l], s[r]);
            l++;
            r--;
        }
        return s;
    }
};