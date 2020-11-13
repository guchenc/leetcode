/*
 * @Description: 2的幂
 * @Author: guchen
 * @Date: 2020-11-13 16:56:28
 * @LastEditTime: 2020-11-13 16:56:38
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        while (n > 0) {
            cnt += n & 0x1;
            n >>= 1;
        }
        return cnt == 1;
    }
};