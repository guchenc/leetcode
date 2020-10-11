/*
 * @Description: 旋转矩阵
 * @Author: guchen
 * @Date: 2020-10-11 21:11:30
 * @LastEditTime: 2020-10-11 21:40:31
 */
#include <vector>
using namespace std;

class Solution {
public:
    // 原地算法 根据观察找到相关的4个坐标 time: O(n^2) space: O(1)
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n - i - 1; j++) {
                int temp = matrix[i][j];
                swap(matrix[n - 1 - j][i], matrix[i][j]);
                swap(matrix[n - 1 - i][n - 1 - j], matrix[n - 1 - j][i]);
                swap(matrix[j][n - 1 - i], matrix[n - 1 - i][n - 1 -j]);
                matrix[j][n - 1 - i] = temp;
            }
        }
    }

    // 暴力求解 time: O(n^2) space: O(n^2)
    void rotate1(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> temp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[j][n - i - 1] = matrix[i][j];
            }
        }
        // for (auto& v : temp) {
        //     for (auto& n : v) {
        //         cout << n << " ";
        //     }
        //     cout << endl;
        // }
        matrix.assign(temp.begin(), temp.end());
    }
};