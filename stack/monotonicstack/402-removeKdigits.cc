/*
 * @Description: 移掉K位数字（使得剩下的数字最小，延伸 最大）
 * @Author: guchen
 * @Date: 2020-12-02 10:57:08
 * @LastEditTime: 2020-12-02 11:07:25
 */
#include "../../alg.h"

class Solution {
public:
    // 复习 利用vector维护单调栈 注意都是字符操作
    string removeKdigits(string num, int k) {
        if (k == 0) return num; 
        string s;
        vector<char> ups;   // vector实现单调栈，方便随机存取
        ups.push_back(num[0]);
        for (int i = 1; i < num.size(); i++) {
            while (k > 0 && !ups.empty() && ups.back() > num[i]) {     // remove bigger digit from front, 注意是循环！！因为要维护单调栈的性质
                ups.pop_back();
                k--;
            }
            ups.push_back(num[i]);
        }
        while (k > 0) { // ups non-strictly increase, remove digit from back
            ups.pop_back(); 
            k--;
        }
        int idx = 0;
        while (idx < ups.size() && ups[idx] == '0') idx++;    // remove prefix zero
        if (idx == ups.size()) return "0";
        while (idx < ups.size()) s += ups[idx++];
        return s;
    }

    // 使用vector实现stack，stack没有迭代器，改用vector就可以顺序访问而不用逆序一遍了
    string removeKdigits3(string num, int k) {
        string res;
        vector<char> ups;
        ups.push_back(num[0]);
        for (int i = 1; i < num.size(); i++) {
            while (k > 0 && !ups.empty() && num[i] < ups.back()) {
                ups.pop_back();
                k--;
            }
            ups.push_back(num[i]);
        }
        while (k > 0) {
            ups.pop_back();
            k--;
        }
        bool flag = false;
        for (int i = 0; i < ups.size(); i++) {
            if (!flag && ups[i] != '0') flag = true; 
            if (flag) res += ups[i];
        }
        return flag == false ? "0" : res;
    }

    // 维护单调栈(<=)
    string removeKdigits2(string num, int k) {
        string res;
        stack<char> ups;
        ups.push(num[0]);
        for (int i = 1; i < num.size(); i++) {
            while (k > 0 && !ups.empty() && num[i] < ups.top()) {
                ups.pop();
                k--;
            }
            ups.push(num[i]);
        }
        while (!ups.empty()) {
            if (k == 0) res.push_back(ups.top());
            if (k > 0) k--;
            ups.pop();
        }
        reverse(res.begin(), res.end());
        int i = 0;
        for (i = 0; i < res.size(); i++) 
            if (res[i] != '0') break;
        if (i == res.size()) return "0";
        return res.substr(i, res.size() - i);
    }

    // 傻吊解法
    string removeKdigits1(string num, int k) {
        string res;
        int j = -1;
        for (int i = 0; i < num.size() - 1; i++) {
            if (num[i] <= num[i + 1] && j == -1) j = i == 0 ? 0 : i - 1;
            int next = i + 1;
            while (next < num.size() && num[next] == '-') next++;
            if (num[i] > num[next]) {
                num[i] = '-';
                if (j != -1) {
                    i = j;
                    j = -1;
                }
                cout << k << " ";
        for (auto c : num) cout << c << " ";
        cout << i <<  endl;
                if (--k == 0) break;
            }
        }
        int idx = num.size() - 1;
        int prev = idx - 1;
        while (k > 0) {
            if (num[idx] != '-') {
                while (prev >= 0 && num[prev] == '-') prev--;
                if (num[idx] >= num[prev]) {
                    num[idx] = '-';
                    k--;
                    idx--;
                }
            }
        }
        bool flag = false;
        for (int i = 0; i < num.size(); i++) {
            if (!flag && num[i] != '-' && num[i] != '0') flag = true;
            if (flag) {
                if (num[i] == '-') continue;
                res.push_back(num[i]);
            } 
        }
        if (!flag) res.push_back('0');
        // for (auto c : num) cout << c << " ";
        // cout << endl;
        return res;
    }
};
