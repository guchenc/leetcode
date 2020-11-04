/*
 * @Description: 括号生成
 * @Author: guchen
 * @Date: 2020-11-03 20:32:26
 * @LastEditTime: 2020-11-03 20:32:39
 */
#include "../alg.h"
class Solution {
public:

    // 针对暴力解法的优化，通过判断左右括号的个数是否有效实现减枝
    // time: O(?) space: O(2*n)
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        vector<char> ans(2 * n);
        generate(res, ans, n, 0, 0, 0);
        return res;
    }

    void generate(vector<string>& res, vector<char>& ans, int n, int idx, int lcnt, int rcnt) {
        if (rcnt > lcnt || lcnt > n || rcnt > n) return;
        if (idx == n * 2) {
            res.emplace_back(ans.begin(), ans.end());
            return;
        }
        ans[idx] = '(';
        generate(res, ans, n, idx + 1, lcnt + 1, rcnt);
        ans[idx] = ')';
        generate(res, ans, n, idx + 1, lcnt, rcnt + 1);
    }

    // 利用递归枚举所有可能的括号序列(2 * n)，判断括号序列是否有效
    // time: O(4^n * n) space: O(2*n)
    vector<string> generateParenthesis1(int n) {
        vector<string> res;
        vector<char> ans(2 * n);
        generate1(res, ans, n * 2, 0);
        return res;
    }

    void generate1(vector<string>& res, vector<char>& ans, int n, int idx) {
        if (idx == n) {
            if (isValid(ans))
                // cout << string(ans.begin(), ans.end()) << endl;
                res.emplace_back(ans.begin(), ans.end());   
            return;
        }   
        ans[idx] = '(';
        generate1(res, ans, n, idx + 1);
        ans[idx] = ')';
        generate1(res, ans, n, idx + 1);
    }

    // 不使用栈 time: O(n) space: O(1)
    bool isValid(vector<char>& ans) {
        int balance = 0;
        for (auto& n : ans) {
            if (n == '(') balance++;
            else balance--;
            if (balance < 0) return false;
        }
        return balance == 0;
    }
    // 利用栈实现括号匹配 time: O(n) space: O(n)
    bool isValid1(vector<char>& ans) {
        stack<char> s;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == '(') s.push(ans[i]);
            else {
                if (s.empty()) return false;
                s.pop();
            }
        }
        return s.empty();
    }
};