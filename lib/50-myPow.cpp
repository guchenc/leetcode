/*
 * @Description: Pow(x, n)
 * @Author: guchen
 * @Date: 2020-11-15 18:31:22
 * @LastEditTime: 2020-11-15 18:31:31
 */
class Solution {
public:
    // 分治法，每次将累乘次数减小一半，time: O(logn) space: O(logn)
    double myPow(double x, int n) {
        long cnt = n;
        if (n < 0) {
            x = 1 / x;
            cnt = -cnt;
        }
        return helper(x, cnt);
    }

    double helper(double x, long n) {
        if (n == 0) return 1;
        if (n % 2 == 0) {
            double half = helper(x, n / 2);
            return half * half; // 包含记忆化的思想，而不是helper(x, n / 2) * helper(x, n / 2)
        } else {
            double half = helper(x, n / 2);
            return half * half * x;
        }
    }
};
