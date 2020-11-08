/*
 * @Description: 搜索二维矩阵II
 * @Author: guchen
 * @Date: 2020-11-08 18:41:53
 * @LastEditTime: 2020-11-08 18:42:05
 */
#include "../alg.h"
class Solution {
public:
    // 从右上角将二维数组看成二叉搜索树
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int r = matrix.size(), c = matrix[0].size();
        int i = 0, j = c - 1;
        while (i < r && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) i++;
            else if (matrix[i][j] > target) j--;
        }
        return false;
    }

};