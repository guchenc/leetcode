/*
 * @Description: 计数质数
 * @Author: guchen
 * @Date: 2020-10-28 20:58:04
 * @LastEditTime: 2020-12-03 15:31:00
 */
#include "../alg.h"
class Solution {
public:
    // dec 3: 暴力解法
    int countPrimes(int n) {
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            bool flag = true;
            for (int j = 2; j < i; j++) {
                if (i % j == 0) flag = false; 
            }
            if (flag) cnt++;
        }
        return cnt;
    }

    // dec 3: 精简版 厄拉多塞筛法
    int countPrimes3(int n) {
        int cnt = 0;
        vector<bool> isPrime(n, true);  // assume all element are prime
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                cnt++;
                for (int j = i + i; j < n; j += i)  // 注意这里是不断+i，e.g. 2 4 6 8 10 ...
                    isPrime[j] = false;
                // int k = 2, tmp = i * 2;
                // while (tmp < n) {
                //     isPrime[tmp] = false;
                //     k++;
                //     tmp = i * k;
                // }
            }
        }
        return cnt;
    }

    // dec 3：写错了 留着回顾
    int countPrimes2(int n) {
        int cnt = 0;
        vector<bool> excluded(n);
        for (int i = 2; i < n; i++) {
            if (excluded[i]) continue;
            bool flag = true;
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    flag = false;
                    int tmp = i;
                    while (tmp < n) {
                        excluded[tmp] = true;
                        tmp += i;
                    }
                    break;
                }
            }
            if (flag)
                cnt++;
        }
        return cnt;
    }

    // 厄拉多塞筛法 超时
    // 建立一个n大小的向量temp，0,1不是质数故temp[0] = 0 temp[1] = 0
    // 2是第一个质数，令[2-n)之间的所有2的位数位为0
    // 以此类推
    int countPrimes1(int n) {
        if (n < 2) return 0;
        int res = 0;
        vector<int> temp(n, 1);
        // temp[0] = 0, temp[1] = 0;
        for (int i = 2; i < n; i++) {
            if (temp[i] == 1) {
                res++;
                for (int j = i + i; j < n; j = j + i)
                    temp[j] = 0;
            }
        }
        return res;
    }
};