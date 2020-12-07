/*
 * @Description: 翻转矩阵后的得分
 * @Author: guchen
 * @Date: 2020-12-07 14:04:06
 * @LastEditTime: 2020-12-07 14:09:53
 */
#include "../alg.h"
class Solution {
public:
    // 贪心算法
    int matrixScore(vector<vector<int>>& A) {
        int res = 0;
        int R = A.size(), C = A[0].size();
        for (int i = 0; i < R; i++) {
            if (A[i][0] == 1) continue; 
            for (int j = 0; j < C; j++)
                A[i][j] = (A[i][j] + 1) % 2;
        }
        for (int j = 1; j < C; j++) {
            int zeroCnt = 0;
            for (int i = 0; i < R; i++) {
                if (A[i][j] == 0) zeroCnt++;
            }
            if (zeroCnt <= R / 2) continue;
            for (int i = 0; i < R ;i++)
                A[i][j] = (A[i][j] + 1) % 2;
        }
        // for (auto r : A) {
        //     for (auto c : r) cout << c << " ";
        //     cout << endl;
        // }
        int row = 0; 
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++)
                row += A[i][j] << (C - 1 - j);
            res += row;
            row = 0;
        }
        return res;
    }
};