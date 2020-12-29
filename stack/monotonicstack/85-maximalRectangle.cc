/*
 * @Description: 最大矩形
 * @Author: guchen
 * @Date: 2020-12-29 21:13:37
 * @LastEditTime: 2020-12-29 21:13:52
 */
#include "../alg.h"
class Solution {
public:
    // 单调栈 可以转换为求子问题：LC84 求柱状图中最大矩形的面积 time: O(r*c) space: O(r*c)
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int ret = INT_MIN;
        int R = matrix.size(), C = matrix[0].size();
        vector<vector<int>> digitMatrix(R, vector<int>(C + 1, 0));
        for (int j = 0; j < C; j++) {
            int height = 0;
            for (int i = 0; i < R; i++) {
                if (matrix[i][j] == '1') digitMatrix[i][j] = ++height;
                else height = 0;
            }
        }
        // for (auto r : digitMatrix) {
        //     for (auto c : r) cout << c << " ";
        //     cout << endl;
        // }

        for (int i = 0; i < R; i++)
            ret = max(ret, maxRectangleInHistogram(digitMatrix[i]));
        return ret == INT_MIN ? 0 : ret;
    }

    int maxRectangleInHistogram(vector<int>& row) {
        int ret = 0;
        stack<int> s;
        for (int i = 0; i < row.size(); i++) {
            while (!s.empty() && row[s.top()] > row[i]) {
                int width = 0, height = row[s.top()]; s.pop();
                if (s.empty()) width = i;
                else width = i - s.top() - 1;
                ret = max(ret, width * height);
            }
            s.push(i);
        }
        return ret;
    }
};
