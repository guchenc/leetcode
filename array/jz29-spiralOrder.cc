/*
 * @Description: 顺时针打印矩阵
 * @Author: guchen
 * @Date: 2020-12-10 20:23:36
 * @LastEditTime: 2020-12-10 20:23:57
 */
#include "../alg.h"
class Solution {
public:
    // 暴力模拟，比方法1好，少了很多判断
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int R = matrix.size(), C = matrix[0].size();
        int right = C - 1, down = R - 1, left = 0, up = 0;  // 四个边界，限制矩形
        int x = 0, y = -1;  // 当前位置
        while (1) {
            while (y + 1 <= right) res.push_back(matrix[x][++y]);
            if (up++ == down) break;
            while (x + 1 <= down) res.push_back(matrix[++x][y]);
            if (right-- == left) break;
            while (y - 1 >= left) res.push_back(matrix[x][--y]);
            if (down-- == up) break;
            while (x - 1 >= up) res.push_back(matrix[--x][y]);
            if (left++ == right) break;
        }
        return res;
    }

    // 暴力模拟 time: O(r*c) space: O(1)
    // 经过的位置值修改为INT_MAX，或者用额外的visited数组
    vector<int> spiralOrder1(vector<vector<int>>& matrix) {
        enum dir {UP, DOWN, LEFT, RIGHT};
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int R = matrix.size(), C = matrix[0].size();
        dir cur = RIGHT;
        int x = 0, y = -1;
        int left = R * C;
        while (left > 0) {
            switch (cur) {
                case RIGHT:
                    while (y + 1 < C && matrix[x][y + 1] != INT_MAX) {
                        y++;
                        res.push_back(matrix[x][y]);
                        matrix[x][y] = INT_MAX;
                        left--;
                    }
                    cur = DOWN;
                    break;
                case DOWN:
                    while (x + 1 < R && matrix[x + 1][y] != INT_MAX) {
                        x++;
                        res.push_back(matrix[x][y]);
                        matrix[x][y] = INT_MAX;
                        left--;
                    }
                    cur = LEFT;
                    break;
                case LEFT:
                    while (y - 1 >= 0 && matrix[x][y - 1] != INT_MAX) {
                        y--;
                        res.push_back(matrix[x][y]);
                        matrix[x][y] = INT_MAX;
                        left--;
                    }
                    cur = UP;
                    break;
                case UP:
                    while (x - 1 >= 0 && matrix[x - 1][y] != INT_MAX) {
                        x--;
                        res.push_back(matrix[x][y]);
                        matrix[x][y] = INT_MAX;
                        left--;
                    }
                    cur = RIGHT;
                    break;
                default: break;
            }
        }
        return res;
    }
};