/*
 * @Description: 整数拆分
 * @Author: guchen
 * @Date: 2020-12-07 20:10:01
 * @LastEditTime: 2020-12-07 20:15:52
 */
#include "../alg.h"
class Solution {
public:
    // 方法2的精简版
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int res = 1;
        while (n > 4) {
            res *= 3;
            n -= 3;
        }
        // 此时n只可能为2 3 4
        return res * n;
    }
    
    // 数学规律 time: O(1) space: O(1)
    // 能拆除3就拆3，若剩1则将其与一个3拼凑4，若剩2直接累乘
    int integerBreak2(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int threeCnt = n / 3;
        int left = n % 3;
        if (left == 1) return pow(3, threeCnt - 1) * 4;
        if (left == 2) return pow(3, threeCnt) * 2;
        return pow(3, threeCnt);
    }

    // DP time: O(n^2) space: O(n)
    // - dp[i]表示将整数i拆分成若干个大于1的整数后所能获得的最大乘积
    // - dp[i] = max {max(j * (i - j), j * dp[i - j])} (0 < j < i)
    int integerBreak1(int n) {
        vector<int> dp(n + 1, INT_MIN);
        dp[0] = dp[1] = 0;
        for (int i = 2; i < n + 1; i++) {
            for (int j = 1; j < i; j++)
                dp[i] = max(dp[i], j * max(i - j, dp[i - j]));
        }
        return dp[n];
    }
};