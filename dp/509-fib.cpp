/*
 * @Description: 斐波那契数列
 * @Author: guchen
 * @Date: 2020-11-14 17:33:42
 * @LastEditTime: 2020-11-14 17:33:59
 */
class Solution {
public:
    // 记忆化递归
    int m[31] = {0, 1};
    int fib(int N) {
        if (N < 2) return N;
        if (m[N] > 0) return m[N];
        m[N] = fib(N - 1) + fib(N - 2);
        return m[N];
    }

    // 迭代 类似DP
    int fib2(int N) {
        if (N < 2) return N;
        int n1 = 0, n2 = 1;
        for (int i = 2; i <= N; i++) {
            int tmp = n1 + n2;
            n1 = n2;
            n2 = tmp;
        }    
        return n2;
    }

    // 最简单的递归，包含大量的重复计算，超时
    int fib1(int N) {
        if (N < 2) return N;
        return fib(N - 1) + fib(N - 2);
    }
};
