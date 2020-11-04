/*
 * @Description: 有效的山脉数组
 * @Author: guchen
 * @Date: 2020-11-03 20:34:37
 * @LastEditTime: 2020-11-03 20:34:46
 */
#include "../alg.h"

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) return false;
        int i = 0;
        while (i + 1 < A.size() && A[i + 1] > A[i]) i++;
        if (i == 0 || i + 1 == A.size()) return false;
        while (i + 1 < A.size() && A[i + 1] < A[i]) i++;
        return i == A.size() - 1;
    }

    bool validMountainArray1(vector<int>& A) {
        if (A.size() < 3) return false;
        bool up = true, flag = false;
        for (int i = 0; i < A.size() - 1; i++) {
            if (up) {
                if (A[i + 1] > A[i]) {
                    flag = true;
                    continue;
                } else if (A[i + 1] == A[i]) return false;
                else up = false;
            } else {
                if (A[i + 1] >= A[i]) return false;
            }
        }
        return !up && flag;
    }
};