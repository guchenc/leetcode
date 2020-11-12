/*
 * @Description: 按奇偶排序数组II
 * @Author: guchen
 * @Date: 2020-11-12 20:24:55
 * @LastEditTime: 2020-11-12 20:25:20
 */
#include "../alg.h"

class Solution {
public:
    // 原地算法 time: O(n) space: O(1)
    vector<int> sortArrayByParityII(vector<int>& A) {
        int j = 1;
        for (int i = 0; i < A.size(); i += 2) {
            if (A[i] & 0x1) {
                while ((A[j] & 0x1) != 0) j += 2;
                swap(A[i], A[j]);
            }
        }
        return A;
    }

    // time: O(n) space: O(1)
    vector<int> sortArrayByParityII1(vector<int>& A) {
        int len = A.size();
        vector<int> res(len);
        int oddp = 1, evenp = 0;
        for (int i = 0; i < len; i++) {
            if (!(A[i] & 0x1)) {
                res[evenp] = A[i];
                evenp += 2;
            } else {
                res[oddp] = A[i];
                oddp += 2;
            }
        }
        return res;
    }
};
