/*
 * @Description: 对角线遍历
 * @Author: guchen
 * @Date: 2020-10-12 08:33:06
 * @LastEditTime: 2020-10-12 10:56:30
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 根据每次终点坐标获取下一次起点坐标
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0) return res;
        int r = matrix.size(), c = matrix[0].size();
        int x = 0, y = 0;
        bool top = true;
        for (int i = 0; i < r + c - 1; i++) {
            if (top) {
                while (x >= 0 && y < c) res.push_back(matrix[x--][y++]);
                x++; y--;
                if (y != c - 1) y++;
                else x++;
                top = false;
            } else {
                while (x < r && y >= 0) res.push_back(matrix[x++][y--]);
                x--; y++;
                if (x != r - 1) x++;
                else y++;
                top = true;
            }
        }
        return res;
    }

    // 直接解法
    vector<int> findDiagonalOrder1(vector<vector<int>>& matrix) {
        vector<int> res, temp;
        if (matrix.size() == 0) return res;
        int r = matrix.size(), c = matrix[0].size();
        int x, y;
        for (int i = 0; i < r + c - 1; i++) {
            x = 0, y = i;
            while (y >= c) {
                x++; y--;
            }
            while (x < r && y >= 0) temp.push_back(matrix[x++][y--]);
            if (!(i % 2)) reverse(temp.begin(), temp.end());
            res.insert(res.end(), temp.begin(), temp.end());
            temp.clear();
        }
        return res;
    }
};