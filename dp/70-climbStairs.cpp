/*
 * @Description: 爬楼梯
 * @Author: guchen
 * @Date: 2020-10-24 15:28:26
 * @LastEditTime: 2020-10-24 15:28:37
 */
#include "../alg.h"
class Solution {
public:
    // time: O(n) space: O(1)
    // 进一步优化，当计算当前台阶走法时只依赖前两个位置的走法，不需要维护所有位置的走法
    int climbStairs(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        int step1 = 1, step2 = 2, step;
        for (int i = 3; i < n + 1; i++) {
            step = step1 + step2;
            step1 = step2;
            step2 = step;
        }
        return step;
    }

    // DP time: O(n) space: O(n)
    // dp[i]表示i阶台阶有多少种走法
    // dp[i] = dp[i - 1] + dp[i -2] (2 <= i <= n)
    int climbStairs4(int n) {
        if (n <= 1) return 1;
        vector<int> dp(n + 1, 0);
        dp[1] = 1, dp[2] = 2; 
        for (int i = 3; i < n + 1; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }

    // 类似fibonacci F(n) = F(n - 1) + F(n - 2)
    // time: O(n) space: O(n)
    unordered_map<int, int> m; 
    int climbStairs3(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (m.find(n) != m.end()) return m[n];
        int ans = climbStairs(n - 1) + climbStairs(n - 2);
        m[n] = ans;
        return ans;
    }

    // 类似fibonacci F(n) = F(n - 1) + F(n - 2)
    // time: O(2^n) space: O(n)
    int climbStairs2(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }

    // 递归 超时
    // 每次攀爬有2种选择，递归树叶子节点为n时，表明攀爬路线符合要求
    // vector<int> ans;
    int climbStairs1(int n) {
        int res = 0;
        oneclimb(n, res, 0);
        return res;
    }
    void oneclimb(int n, int& res, int total) {
        if (total >= n) {
            if (total == n) {
                // for (auto s : ans) cout << s << " ";
                // cout << endl;
                res++;
            } 
            return;
        }
        // ans.push_back(1);
        oneclimb(n, res, total + 1);
        // ans.pop_back();
        // ans.push_back(2);
        oneclimb(n, res, total + 2);
        // ans.pop_back();
    }
};