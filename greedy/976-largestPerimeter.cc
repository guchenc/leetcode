/*
 * @Description: 三角形的最大周长
 * @Author: guchen
 * @Date: 2020-11-30 16:56:11
 * @LastEditTime: 2020-11-30 16:56:38
 */
#include "../alg.h"
class Solution {
public:
    // 求可构成三角形的最大周长
    // - 先排序，从大的边开始找
    // - 若两个较大边a b相加都小于更大的边c，那么两个较大边a b之前的边相加肯定也小于更大的边c，故没必要在保留边c的情况下继续向前寻找更小的边，且边c一定构不成三角形，直接丢弃
    // time: O(nlogn) space: O(logn)
    int largestPerimeter(vector<int>& A) {
        int N = A.size();
        if (N < 3) return 0;
        sort(A.begin(), A.end());
        for (int i = N - 1; i >= 2; i--)
            if (A[i - 2] + A[i - 1] > A[i]) return A[i - 2] + A[i - 1] + A[i];
        return 0;
    }

    int largestPerimeter3(vector<int>& A) {
        int N = A.size();
        if (N < 3) return 0;
        sort(A.begin(), A.end());
        for (int i = N - 1; i >= 2; i--) {
            for (int j = i - 1; j >= 1; j--) {
                for (int k = j - 1; k >= 0; k--) {
                    cout << A[i] << " " << A[j] << " " << A[k] << endl;
                    if (isValid(A, i, j, k)) return A[i] + A[j] + A[k];
                }
            }
        }
        return 0;
    }

    // 暴力解法优化版 time: O(n^3) space: O(logn)
    int largestPerimeter2(vector<int>& A) {
        int N = A.size();
        if (N < 3) return 0;
        int res = 0;
        sort(A.begin(), A.end());
        for (int i = 0; i < N - 2; i++) {
            for (int j = i + 1; j < N - 1; j++) {
                for (int k = j + 1; k < N; k++) {
                    if (A[i] + A[j] <= A[k]) break;
                    res = max(res, A[i] + A[j] + A[k]);
                }
            }
        }
        return res;

    }

    // 暴力解法 time: O(n^3) space: O(1)
    int largestPerimeter1(vector<int>& A) {
        int N = A.size();
        if (N < 3) return 0;  
        int res = 0;
        for (int i = 0; i < N - 2; i++) {
            for (int j = i + 1; j < N - 1; j++) {
                for (int k = j + 1; k < N; k++) {
                    if (isValid(A, i, j, k))
                        res = max(res, A[i] + A[j] + A[k]);
                }
            }
        }
        return res;
    }

    bool isValid(vector<int>& A, int i, int j, int k) {
        return A[i] + A[j] > A[k] && A[i] + A[k] > A[j] && A[j] + A[k] > A[i];
    }
};