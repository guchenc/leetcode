#include <queue>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // DP time: O(r*c) space: O(1)
    // 状态: 原始matrix即可作为dp数组记录状态，即matrix[i][j]表示距0的最近距离
    // 状态转移函数: 
    //      - matrix[i][j] == 0: matrix[i][j] = 0;
    //      - matrix[i][j] != 0: matrix[i][j] = min(matrix[i-1][j],matrix[i+1][j],matrix[i][j-1],matrix[i][j+1]) + 1
    //        (注意，matrix[i][j]四个方向上的值不一定有效!!!!)
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int nrow = matrix.size(), ncol = matrix[0].size();
        // 遍历一边二维向量，将1替换为INT32_MAX，作为最大值
        for (int i = 0; i < nrow; i++) {
            for (int j = 0; j < ncol; j++) {
                if (matrix[i][j] == 1) matrix[i][j] = INT32_MAX;
            }
        }
        // 从左到右，从上到下，每次只取左边和上边的最小值进行赋值
        for (int i = 0; i < nrow; i++) {
            for (int j = 0; j < ncol; j++) {
                if (matrix[i][j] == 0) continue;
                if (i - 1 >= 0 && matrix[i - 1][j] < matrix[i][j]) matrix[i][j] = matrix[i - 1][j] + 1;
                if (j - 1 >= 0 && matrix[i][j - 1] < matrix[i][j]) matrix[i][j] = matrix[i][j - 1] + 1;
            }
        }
        // 从右到左，从下到上，每次只取右边和下边的最小值进行赋值
        for (int i = nrow - 1; i >= 0; i--) {
            for (int j = ncol - 1; j >= 0; j--) {
                if (matrix[i][j] == 0) continue;
                if (i + 1 < nrow && matrix[i + 1][j] < matrix[i][j]) matrix[i][j] = matrix[i + 1][j] + 1;
                if (j + 1 < ncol && matrix[i][j + 1] < matrix[i][j]) matrix[i][j] = matrix[i][j + 1] + 1;
            }
        }
        return matrix;
    }

    // 采用BFS求解多源最短路径 time: O(r*c) space: O(r*c)
    vector<vector<int>> updateMatrix2(vector<vector<int>>& matrix) {
        int nrow = matrix.size(), ncol = matrix[0].size();
        // vector<vector<int>> res(nrow, vector<int>(ncol, 0));
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        for (int i = 0; i < nrow; i++) {
            for (int j = 0; j < ncol; j++) {
                if (matrix[i][j] == 0) q.push({i, j});
                else matrix[i][j] = INT32_MAX;
            }
        }

        while (!q.empty()) {
            // print_matrix(matrix);
            int cnt = q.size();
            for (int i = 0; i < cnt; i++) {
                auto p = q.front(); q.pop();
                int x = p.first, y = p.second;
                for (auto d : dirs) {
                    int nx = x + d.first, ny = y + d.second;
                    if (nx >= 0 && nx < nrow && ny >= 0 && ny < ncol && matrix[nx][ny] > matrix[x][y] + 1) {
                        matrix[nx][ny] = matrix[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return matrix;
    }

    void print_matrix(vector<vector<int>>& matrix) {
        for (auto r : matrix) {
            for (auto c : r) {
                if (c == INT32_MAX) cout << "* ";
                else cout << c << " ";
            }
            cout << endl;
        }
        cout << "----------------------------" << endl;
    }
    
    // 对于每个1，采用BFS求解单源最短路径 超时
    vector<vector<int>> updateMatrix1(vector<vector<int>>& matrix) {
        int nrow = matrix.size(), ncol = matrix[0].size();
        for (int i = 0; i < nrow; i++) {
            for (int j = 0; j < ncol; j++) {
                if (matrix[i][j] == 0) continue;
                matrix[i][j] = INT32_MAX;
                updateFrom1(matrix, nrow, ncol, i, j);
            }
        }
        return matrix;
    }

    void updateFrom1(vector<vector<int>>& matrix, int nrow, int ncol, int r, int c) {
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> visited(nrow, vector<bool>(ncol, false));
        int dis = 0;
        q.push({r, c});
        while (!q.empty()) {
            int cnt = q.size();
            dis++;        
            for (int i = 0; i < cnt; i++) {
                auto p = q.front(); q.pop();
                int x = p.first, y = p.second;
                visited[x][y] = true;
                for (auto d : dirs) {
                    int nx = x + d.first, ny = y + d.second;
                    if (nx < 0 || nx >= matrix.size() || ny < 0 || ny >= matrix[0].size() || visited[nx][ny]) continue;
                    if (matrix[nx][ny] == 0) {
                        matrix[r][c] = min(matrix[r][c], dis);
                        break;
                    } 
                    q.push({nx, ny});
                }
            }
        }
    }
    
};