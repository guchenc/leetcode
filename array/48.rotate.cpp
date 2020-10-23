/*
 * @Description: 旋转图像
 * @Author: guchen
 * @Date: 2020-10-23 17:21:37
 * @LastEditTime: 2020-10-23 17:21:56
 */
#include "../alg.h"
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < (n >> 1); ++i){
            for(int j = i; j < n - 1 - i; ++j){
                swap(matrix[i][j], matrix[j][n - 1 - i]);
                swap(matrix[i][j], matrix[n - 1 - i][n - 1 - j]);
                swap(matrix[i][j], matrix[n - 1 - j][i]);
            }
        }
    }
    // 先置换，再将每一行反转 time: O(n^2) space: O(1)
    void rotate1(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i + 1; j < matrix.size(); j++)
                swap(matrix[i][j], matrix[j][i]);
        }
        for (int i = 0; i < matrix.size(); i++) {
            int l = 0, r = matrix.size() - 1;
            while (l < r) {
                swap(matrix[i][l], matrix[i][r]);
                l++;
                r--;
            }
        }
    }
};