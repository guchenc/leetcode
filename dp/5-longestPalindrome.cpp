/*
 * @Description: 最长回文字符串
 * @Author: guchen
 * @Date: 2020-09-16 18:35:12
 * @LastEditTime: 2020-09-17 16:19:10
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // 回文字符串天然具有动态转移，因此采用DP求解，用空间换取时间，但是只是对暴力解法的优化，依然很耗时
    // time: O(n^2) space: O(n^2)
    // 状态: dp[i][j]表示子串[i, j]是否是回文子串
    // 状态转移函数: dp[i][j] = (s[i] == s[j]) and dp[i + 1][j - 1]
    // 边界条件: (j - 1) - (i + 1) + 1 < 2 => j - i < 3 (j-i+1<4, 即s[i,j]长度为2 3不用检查回文，因为此时包括了子串两头的字符，若去掉，剩下的字符数为0/1,显然不需要判断是否是回文) 
    // 初始化: dp[i][i] = true
    string longestPalindrome(string s) {
        int len = s.size();
        if (len < 2)
            return s;
        int start = 0;
        int maxlen = 1;
        bool dp[len][len];  //需要手动for循环初始化，改用vector
        //vector<vector<bool>> dp(len, vector<bool>(len, false));
        for (int i = 0; i < len; i++)
            dp[i][i] = true;
        for (int j = 1; j < len; j++) {
            for (int i = 0; i < j; i++) {
                if (s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    int cur_maxlen = j - i + 1;
                    if (cur_maxlen > maxlen) {
                        maxlen = cur_maxlen;
                        start = i;
                    }
                    continue;
                }
                dp[i][j] = false;
            }
        }
        return s.substr(start, maxlen);
    }
    
    // 算是除马拉车算法外的最优解法
    // 依次以字符串[0,s.size() - 2]的字符为单中心回文串中心,
    // 以字符串中相邻字符对(n, n+1)，其中n属于[0, s.size() - 2]，为双中心回文串中心，
    // 向外扩充，直至不构成回文串，比较两种情况下能够成最大回文串的长度，记录最大回文串的起始位置和长度
    // time: O(n^2) space: O(1)
    string longestPalindrome1(string s) {
        if (s.size() < 2)
            return s;
        int start = 0;
        int maxlen = 1;
        for (int i = 0; i < s.size() - 1; i++) {
            int onemid = expand_around_center(s, i, i);
            int twomid = expand_around_center(s, i, i + 1);
            // cout << "onemid = " << onemid << " twomid= " << twomid << endl;
            if (onemid >= twomid) {
                if (onemid > maxlen) {
                    maxlen = onemid;
                    start = i - (onemid - 1) / 2;
                }
            } else {
                if (twomid > maxlen) {
                    start = i - (twomid - 2) / 2;
                    maxlen = twomid;
                }
            }
        }
        // cout << start << " " << maxlen << endl;
        return s.substr(start, maxlen);
    }

    // 根据中心点向外扩散，中心点存在两种情况，单个中心点，两个中心点
    int expand_around_center(string& s, int left, int right) {
        int l = left;
        int r = right;
        while (l >=  0 && r < s.size()) {
            if (s[l] == s[r]) {
                l--;
                r++;
            } else {
                break;
            }
        }
        return r - l - 1;   // 因为终止时，l和r都比实际位置多移动1位，根据图推出
    }

    // direct solution s.size() <= 1000 O(n^2) is acceptable, in fact, over time..
    // time: O(n^3) ?  space: O(1)
    string longestPalindrome2(string s) {
        if (s.size() < 2)
            return s;
        int start = 0;
        int maxlen = 1;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                int len = j - i + 1;
                if (isPalindrome(s, i, j) && len > maxlen) {
                    start = i;
                    maxlen = len; 
                }
            }
        }
        return s.substr(start, maxlen);
    }

    bool isPalindrome(string& s, int begin, int end) {
        if (begin < 0 || end >= s.size())
            return false;
        int left = begin, right = end;
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution so;
    string s, res;
    while (getline(cin, s)) {
        res = so.longestPalindrome1(s);
        cout << "max palindrome of " << s << " : " << res << endl;
    }
}