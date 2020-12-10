/*
 * @Description: 螺旋矩阵
 * @Author: guchen
 * @Date: 2020-12-10 20:22:44
 * @LastEditTime: 2020-12-10 20:22:55
 */
#include "../alg.h"
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int R = matrix.size(), C = matrix[0].size();
        int right = C - 1, down = R - 1, left = 0, up = 0;
        int x = 0, y = -1;
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
};