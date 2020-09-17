/*
 * @Description: ������ַ���
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
    // �����ַ�����Ȼ���ж�̬ת�ƣ���˲���DP��⣬�ÿռ任ȡʱ�䣬����ֻ�ǶԱ����ⷨ���Ż�����Ȼ�ܺ�ʱ
    // time: O(n^2) space: O(n^2)
    // ״̬: dp[i][j]��ʾ�Ӵ�[i, j]�Ƿ��ǻ����Ӵ�
    // ״̬ת�ƺ���: dp[i][j] = (s[i] == s[j]) and dp[i + 1][j - 1]
    // �߽�����: (j - 1) - (i + 1) + 1 < 2 => j - i < 3 (j-i+1<4, ��s[i,j]����Ϊ2 3���ü����ģ���Ϊ��ʱ�������Ӵ���ͷ���ַ�����ȥ����ʣ�µ��ַ���Ϊ0/1,��Ȼ����Ҫ�ж��Ƿ��ǻ���) 
    // ��ʼ��: dp[i][i] = true
    string longestPalindrome(string s) {
        int len = s.size();
        if (len < 2)
            return s;
        int start = 0;
        int maxlen = 1;
        bool dp[len][len];  //��Ҫ�ֶ�forѭ����ʼ��������vector
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
    
    // ���ǳ��������㷨������Žⷨ
    // �������ַ���[0,s.size() - 2]���ַ�Ϊ�����Ļ��Ĵ�����,
    // ���ַ����������ַ���(n, n+1)������n����[0, s.size() - 2]��Ϊ˫���Ļ��Ĵ����ģ�
    // �������䣬ֱ�������ɻ��Ĵ����Ƚ�����������ܹ��������Ĵ��ĳ��ȣ���¼�����Ĵ�����ʼλ�úͳ���
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

    // �������ĵ�������ɢ�����ĵ��������������������ĵ㣬�������ĵ�
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
        return r - l - 1;   // ��Ϊ��ֹʱ��l��r����ʵ��λ�ö��ƶ�1λ������ͼ�Ƴ�
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