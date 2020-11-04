/*
 * @Description: 搜索二维矩阵
 * @Author: guchen
 * @Date: 2020-11-04 19:28:33
 * @LastEditTime: 2020-11-04 19:28:44
 */
#include "../alg.h"
class Solution {
public:
    // 将二维数组看成有序一维数组，使用二分查找 time: O(logn) space: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int nr = matrix.size(), nc = matrix[0].size();
        int l = 0, r = nr * nc - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = matrix[mid / nc][mid % nc];
            // cout << mid / nc << " " << mid % nc - 1 << endl;
            if (target > val) l = mid + 1;
            else if (target < val) r = mid - 1;
            else return true;
        }
        return false;
    }

    // 直接解法 time: O(n + m) space: O(1)
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int row = -1;
        int r = matrix.size(), c = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[r - 1][c - 1]) return false;
        for (int i = 0; i < r; i++) {
            if (target > matrix[i][0]) row = i;
            else if (target < matrix[i][0]) break;
            else return true;
        }
        for (int j = 0; j < c; j++) {
            if (target == matrix[row][j]) return true;
        }
        return false;
    }
};