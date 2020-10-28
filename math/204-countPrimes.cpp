/*
 * @Description: 计数质数
 * @Author: guchen
 * @Date: 2020-10-28 20:58:04
 * @LastEditTime: 2020-10-28 20:58:13
 */
#include "../alg.h"
class Solution {
public:

    // 厄拉多塞筛法 超时
    // 建立一个n大小的向量temp，0,1不是质数故temp[0] = 0 temp[1] = 0
    // 2是第一个质数，令[2-n)之间的所有2的位数位为0
    // 以此类推
    int countPrimes(int n) {
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