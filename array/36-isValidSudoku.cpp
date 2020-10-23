/*
 * @Description: 有效数独
 * @Author: guchen
 * @Date: 2020-10-23 17:22:30
 * @LastEditTime: 2020-10-23 17:24:14
 */
#include "../alg.h"
class Solution {
public:
    // 由于题目说明给定永远9*9
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rowexist[9][9] = {false};  // 表示某行是否存在某数字
        bool colexist[9][9] = {false};  // 表示某列是否存在某数字
        bool blockexist[9][9] = {false};// 表示某个块是否存在某数字
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int digit = board[i][j] - '0' - 1;
                if (board[i][j] == '.') continue;
                if (rowexist[i][digit]) return false;
                if (colexist[j][digit]) return false;
                int blkidx =  i - i % 3 + j / 3;
                if (blockexist[blkidx][digit]) return false;
                rowexist[i][digit] = true;
                colexist[j][digit] = true;
                blockexist[blkidx][digit] = true;
            }
        }
        return true;
    }
    // 暴力解法
    bool isValidSudoku1(vector<vector<char>>& board) {
        int n = board.size(); 
        unordered_set<char> s;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 3 == 0 && j % 3 == 0) {
                    for (int m = i; m < i + 3; m++) {
                        for (int n = j; n < j + 3; n++) {
                            char cur = board[m][n];
                            if (cur == '.') continue;
                            if (s.find(cur) != s.end()) return false;
                            s.insert(cur);
                        }
                    }
                    s.clear();
                }
                if (board[i][j] == '.') continue;
                for (int k = 0; k < n; k++)
                    if ((k != j && board[i][k] == board[i][j]) || (k != i && board[k][j] == board[i][j])) return false;
            }
        }
        return true;
    }
};