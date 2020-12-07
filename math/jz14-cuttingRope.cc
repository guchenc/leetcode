/*
 * @Description: 剪绳子
 * @Author: guchen
 * @Date: 2020-12-07 20:06:58
 * @LastEditTime: 2020-12-07 20:09:13
 */
#include "../alg.h"

class Solution {
public:
    // DP time: O(n^2) space: O(n)
    // 与lc343整数拆分相同
    // 2 <= n <= 58
    int cuttingRope(int n) {
        vector<int> dp(n + 1);
        for (int i = 2; i < n + 1; i++) {
            int m = INT_MIN;
            for (int j = 1; j < i; j++)
                m = max(m, j * max(i - j, dp[i - j]));
            dp[i] = m;
        }
        return dp[n];
    }

    // n不受限制，结果需要对1e9 + 7取余
    int cuttingRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        long res = 1;
        while (n > 4) { // 这样最后n可能为 2 3 4
            res *= 3;
            res = res % (long)(1e9 + 7);
            n -= 3;
        }
        return res * n % (long)(1e9 +7);
    }
};