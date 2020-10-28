/*
 * @Description: 颠倒二进制位
 * @Author: guchen
 * @Date: 2020-10-28 21:03:45
 * @LastEditTime: 2020-10-28 21:03:56
 */
#include "../alg.h"
class Solution {
public:
    // 每次取最低位移位后累加
    uint32_t reverseBits1(uint32_t n) {
        uint32_t res = 0;
        int cnt = 0;
        while (n != 0) {
            res += (n & 0x1) << (31 - cnt);
            // cout << bitset<32>(res) << endl;;
            n >>= 1;
            cnt++;
        }
        return res;
    }

    uint32_t reverseBits(uint32_t n) {
        bitset<32> bits(n);
        bitset<32> res(0);
        for (int i = 0; i < 32; i++)
            res[31 - i] = bits[i];
        return res.to_ulong();
    }
};