/*
 * @Description: 字符串相乘
 * @Author: guchen
 * @Date: 2020-09-23 22:08:11
 * @LastEditTime: 2020-09-23 22:14:59
 */
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        if (len1 == 0) return num2;
        if (len2 == 0) return num1;
        int zerocnt = 0;
        string res;
        for (int i = len2 - 1; i >= 0; i--)
            res = add(res, multione(num1, num2[i]).append(zerocnt++, '0'));
        if (res[0] == '0')  return "0"; // 处理"0" "42" 得到"00"这种情况
        return res;
    }

    string add(string& num1, string& num2) {
        int i = num1.size() - 1, j = num2.size() - 1, sum = 0;
        string res;
        while (i >=0 || j >= 0 || sum != 0) {
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

    string add1(string& num1, string& num2) {
        int len1 = num1.size(), len2 = num2.size();
        if (len1 == 0) return num2;
        if (len2 == 0) return num1;
        string temp;
        string res;
        int diff = len1 > len2 ? len1 - len2 : len2 - len1;
        if (len1 > len2) {
            temp.append(diff, '0').append(num2);
            res.resize(len1);
        } else {
            temp.append(diff, '0').append(num1);
            res.resize(len2);
        }
        int sum = 0;
        int i = max(len1, len2) - 1;
        while (i >= 0) {
            if (len1 > len2)
                sum += (num1[i] - '0') + (temp[i] - '0');
            else
                sum += (temp[i] - '0') + (num2[i] - '0');
            res[i] = '0' + sum % 10;
            sum /= 10;
            i--;
        }
        if (sum != 0)
            return "1" + res;
        return res;
    }

    string multione(string& num, char c) {
        int len = num.size();
        int sum = 0;
        string res;
        if (c == '0')
            return "0";
        for (int i = len - 1; i >=0; i--) {
            sum = (num[i] - '0') * (c - '0') + sum;
            res.push_back('0' + sum % 10);
            sum /= 10;
        }
        if (sum != 0)
            res += '0' + sum;
        reverse(res.begin(), res.end());
        return res;
    }
};