/*
 * @Description: 汉明距离
 * @Author: guchen
 * @Date: 2020-10-28 21:02:07
 * @LastEditTime: 2020-10-28 21:02:25
 */
class Solution {
public:
    // 异或后计算为1的位数
    int hammingDistance(int x, int y) {
        int res = 0;
        unsigned temp = x ^ y;
        while (temp > 0) {
            res += (temp & 0x1);
            temp >>= 1;
        }
        return res;
    }
};