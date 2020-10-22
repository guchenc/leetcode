/*
 * @Description: 整数反转
 * @Author: guchen
 * @Date: 2020-10-22 16:05:01
 * @LastEditTime: 2020-10-22 16:05:12
 */
#include "../alg.h"
class Solution {
public:
    // 学会这种思想! 负数求余!
    int reverse(int x) {
        long n = 0;  // 足以容纳32位无符号最大值
        while (x != 0) {
            n = n * 10 + x % 10;
            x /= 10;
        }
        // cout << UINT32_MAX << endl;
        // cout << UINT64_MAX << endl;
        return n > INT_MAX || n < INT_MIN ? 0 : n;
    }
};