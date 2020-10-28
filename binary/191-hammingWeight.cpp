/*
 * @Description: 位1的个数
 * @Author: guchen
 * @Date: 2020-10-28 21:02:49
 * @LastEditTime: 2020-10-28 21:03:00
 */
#include "../alg.h"
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        uint32_t mask = 0x1;
        while (mask != 0) {
            cnt += ((n & mask) == 0 ? 0 : 1);
            mask <<= 1;
        }
        return cnt;
    }

    // 投机取巧型
    int hammingWeight2(uint32_t n) {
        return bitset<32>(n).count();
    }

    // 逐步取最低位累加
    int hammingWeight1(uint32_t n) {
        int cnt = 0;
        while (n > 0) {
            cnt += (n & 0x1);
            n >>= 1;
        }
        return cnt;
    }
};