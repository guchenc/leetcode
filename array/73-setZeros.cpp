/*
 * @Description: 矩阵置零
 * @Author: guchen
 * @Date: 2020-10-28 20:54:01
 * @LastEditTime: 2020-10-28 20:54:11
 */
#include "../alg.h"

class Solution {
public:
    // 用首行和首列记录各行各列是否应该被赋值为0
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        int r = matrix.size(), c = matrix[0].size();
        bool flag = false;
        for (int i = 0; i < r; i++) {
            if (matrix[i][0] == 0) flag = true;
            for (int j = 1; j < c; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        }

        if (matrix[0][0] == 0)
            for (int j = 0; j < c; j++) matrix[0][j] = 0;
        if (flag)
            for (int i = 0; i < r; i++) matrix[i][0] = 0;
    }

    // 遍历一边二维向量，将为0的行列分别加入行set和列set，之后再统一赋值0
    void setZeroes2(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        int r = matrix.size(), c = matrix[0].size();
        set<int> zeroc, zeror;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == 0){
                    zeror.insert(i);
                    zeroc.insert(j);
                }
            }
        }
        for (auto it = zeror.begin(); it != zeror.end(); it++)
            for (int i = 0; i < c; i++) matrix[*it][i] = 0;
        for (auto it = zeroc.begin(); it != zeroc.end(); it++)
            for (int i = 0; i < r; i++) matrix[i][*it] = 0;
    }
    
    // time: O(n * m * (n + m)) space: O(n*m)
    void setZeroes1(vector<vector<int>>& matrix) {
        vector<vector<int>> temp(matrix);
        int r = matrix.size(), c = matrix[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (temp[i][j] == 0) {
                    for (int k = 0; k < r; k++) matrix[k][j] = 0;
                    for (int k = 0; k < c; k++) matrix[i][k] = 0;
                }
            }
        }
    }
};