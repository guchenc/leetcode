/*
 * @Description: 四数相加II
 * @Author: guchen
 * @Date: 2020-11-27 22:41:19
 * @LastEditTime: 2020-11-27 22:41:37
 */
#include "../alg.h"
class Solution {
public:
    // 精简版
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int N = A.size();
        int res = 0;
        unordered_map<int, int> m;
        for (auto a : A) {
            for (auto b : B) {
                m[a + b]++;
            }
        }

        for (auto c : C) {
            for (auto d : D) {
                auto it = m.find(-(c + d));
                if (it != m.end())
                    res += it->second;
            }
        }
        return res;
    }

    // time: O(n^2) space: O(n^2)
    int fourSumCount2(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int N = A.size();
        int res = 0;
        unordered_map<int, int> m;
        // 遍历A和B的所有可能组合，统计所有可能组合的和的出现次数
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int sum = A[i] + B[j];
                auto it = m.find(sum);
                if (it == m.end()) m[sum] = 1;
                else m[sum] += 1;
            }
        }

        // 遍历C和D的所有可能组合的和sum，在哈希表中查找-sum，若存在则将其出现次数加到结果值中
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int sum = C[i] + D[j];
                auto it = m.find(-sum);
                if (it != m.end()) res += it->second;
            }
        }
        return res;
    }

    // 暴力解法 time: O(n^4) space: O(1)
    int fourSumCount1(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int N = A.size();
        int res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int m = 0; m < N; m++) {
                    for (int n = 0; n < N; n++) {
                        if (A[i] + B[j] + C[m] + D[n] == 0) res++;
                    }
                }
            }
        }
        return res;
    }
};