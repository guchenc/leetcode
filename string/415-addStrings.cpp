/*
 * @Description: 字符串相加
 * @Author: guchen
 * @Date: 2020-09-23 21:29:56
 * @LastEditTime: 2020-09-23 21:31:08
 */
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 双指针 time: O(max(m,n)) space: O(1)
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, sum = 0;
        string res;
        while (i >= 0 || j >= 0 || sum != 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            sum += x + y;
            res.push_back('0' + sum % 10);
            sum /= 10;
            i--;j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};