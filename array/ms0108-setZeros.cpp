/*
 * @Description: 零矩阵
 * @Author: guchen
 * @Date: 2020-10-12 06:12:37
 * @LastEditTime: 2020-10-12 06:13:02
 */
#include <vector>
using namespace std;

class Solution {
public:
    // 暴力求解 time: O(n^2) space: O(n)
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zeros;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) zeros.push_back({i, j});
            }
        }
        for (auto& pos : zeros) {
            int x = pos.first, y = pos.second;
            // cout << pos.first << " " << pos.second << endl;
            for (int k = 0; k < matrix[0].size(); k++)  matrix[x][k] = 0;
            for (int k = 0; k < matrix.size(); k++) matrix[k][y] = 0;
        }
        
    }
};