/*
 * @Description: N皇后II
 * @Author: guchen
 * @Date: 2020-10-17 16:06:49
 * @LastEditTime: 2020-10-17 16:07:18
 */
#include "../alg.h"
class Solution {
public:
    // time: O(n!)  space: O(n)
    // int数组queens: queens数组记录了当前皇后的摆放状态, 第i行的queen位于第queens[i]列，queens[i]初始化为-1,最终都将被赋值
    // 通过遍历queens数组来判断位置(i, j)是否可用，每次只需从queens[0]遍历到queens[i - 1]即可，因为此时第i行及之后的皇后摆放位置还没有确定
    //      - queens[k] == j : 说明已经有皇后位于第j列
    //      - (k - queens[k] == i - j) || (k + queens[k] == i + j) : 说明两条斜线方向上已经有皇后
    vector<int> queens;
    int res = 0, N;
    
    int totalNQueens(int n) {
        queens.assign(n, -1);
        N = n;
        place(0);
        return res;
    }

    void place(int i) {
        if (i == N) {
            res++;
            return;
        }
        for (int j = 0; j < N; j++) {
            if (isValid(i, j)) {
                queens[i] = j;
                place(i + 1);
                queens[i] = -1;
            }
        }
    }

    bool isValid(int i, int j) {
        for (int k = 0; k < i; k++) {   // 只需遍历到i
            if (queens[k] == j) return false;   // 检查同一列是否有皇后
            if (k - queens[k] == i - j || k + queens[k] == i + j) return false;   // 检查斜线上是否有皇后
        }
        return true;
    }
};