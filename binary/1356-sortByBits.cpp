/*
 * @Description: 根据数字二进制下1的数目排序
 * @Author: guchen
 * @Date: 2020-11-06 16:56:05
 * @LastEditTime: 2020-11-06 16:56:35
 */
#include "../alg.h"
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int& a, int& b) {
            int acnt = cntBinaryOne(a);
            int bcnt = cntBinaryOne(b);
            if (acnt > bcnt) return false;
            else if (acnt < bcnt) return true;
            else return a < b;
        });
        return arr;
    }

    static int cntBinaryOne(unsigned num) {
        int cnt = 0;
        while (num > 0) {
            cnt += num & 0x1;
            num >>= 1;
        }
        return cnt;
    }
};
