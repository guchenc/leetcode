#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    // 与542本质上是一道题
    // 曼哈顿距离实际上就是某一点到另一点需要经过的格子数，因此本题实际上就是求海洋到陆地的最远距离
    // DP time: O(n) space: O(1)
    int maxDistance(vector<vector<int>>& grid) {
        int nrow = grid.size(), ncol = grid[0].size();
        int res = -1, landcnt = 0;
        for (int i = 0; i < nrow; i++) {
            for (int j = 0; j < ncol; j++) {
                if (grid[i][j] == 0) {
                    grid[i][j] = INT32_MAX;
                    landcnt++;
                } else grid[i][j] = 0;
            }
        }
        if (landcnt == 0 || landcnt == nrow * nrow) return -1;
        for (int i = 0; i < nrow; i++) {
            for (int j = 0; j < ncol; j++) {
                if (grid[i][j] == 1) continue;
                if (i - 1 >= 0 && grid[i - 1][j] < grid[i][j]) grid[i][j] = grid[i - 1][j] + 1;
                if (j - 1 >= 0 && grid[i][j - 1] < grid[i][j]) grid[i][j] = grid[i][j - 1] + 1;
            }
        } 
        for (int i = nrow - 1; i >= 0; i--) {
            for (int j = ncol - 1; j >= 0; j--) {
                if (grid[i][j] == 1) continue;
                if (i + 1 < nrow && grid[i + 1][j] < grid[i][j]) grid[i][j] = grid[i + 1][j] + 1;
                if (j + 1 < ncol && grid[i][j + 1] < grid[i][j]) grid[i][j] = grid[i][j + 1] + 1;
            }
        } 
        for (int i = 0; i < nrow; i++) {
            for (int j = 0; j < ncol; j++) {
                if (grid[i][j] == INT32_MAX) continue;
                res = max(res, grid[i][j]);
            }
        }
        return res;
    }

    // BFS求多源最短路径 time: ? space: ?
    int maxDistance2(vector<vector<int>>& grid) {
        int nrow = grid.size(), ncol = grid[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> visited(nrow, vector<bool>(ncol, false));
        int step = -1;
        for (int i = 0; i < nrow; i++) {
            for (int j = 0; j < ncol; j++) {
                if (grid[i][j] == 1) q.push({i, j});
            }
        }
        if (q.empty() || q.size() == grid.size() * grid.size()) return -1;
        while (!q.empty()) {
            step++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto p = q.front(); q.pop();
                int x = p.first, y = p.second;
                for (auto d : dirs) {
                    int nx = x + d.first, ny = y + d.second;
                    if (nx < 0 || nx >= nrow || ny < 0 || ny >= ncol || grid[nx][ny] == 1 || visited[nx][ny]) continue;
                    q.push({nx, ny});
                    grid[nx][ny] = true;
                }
            }
        }
        return step;
    }

    // 对每个0进行BFS，效率极低! 超时，没得救了! time: O(n^4) space: O(n^2)
    int maxDistance1(vector<vector<int>>& grid) {
        int nrow = grid.size(), ncol = grid[0].size();
        int maxdis = -1;
        queue<pair<int, int>> q;
        // vector<vector<int>> res(grid);
        vector<vector<bool>> allfalse(nrow, vector<bool>(ncol, false));
        // vector<pair<int, int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1,1}};
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        for (int i = 0; i < nrow; i++) {
            for (int j = 0; j < ncol; j++) {
                if (grid[i][j] == 1) {
                    // res[i][j] = INT32_MAX;
                    continue;
                }
                vector<vector<bool>> visited(allfalse);
                int mindis = INT32_MAX;
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty()) {
                    int size = q.size();
                    for (int k = 0; k < size; k++) {
                        auto p = q.front(); q.pop();
                        int x = p.first, y = p.second;
                        for (auto d : dirs) {
                            int nx = x + d.first, ny = y + d.second;
                            if (nx < 0 || nx >= nrow || ny < 0 || ny >= ncol || visited[nx][ny]) continue;
                            if (grid[nx][ny] == 0) {
                                q.push({nx, ny});
                                visited[nx][ny] = true;
                                continue;
                            }
                            mindis = min(mindis, abs(nx - i) + abs(ny - j));
                        }
                    }
                    if (mindis != INT32_MAX) {  // 在向外扩散的过程中只要某一层有1,当处理完该层后就将队列清空，无需继续向外扩散
                        while (!q.empty()) q.pop();
                        break;
                    }
                }
                // res[i][j] = mindis;
                maxdis = max(maxdis, mindis);
            }
        }
        // print_grid(grid);
        // print_grid(res);
        if (maxdis == INT32_MAX) return -1;
        return maxdis;
    }

    void print_grid(vector<vector<int>>& grid) {
        for (auto v : grid) {
            for (auto n : v) {
                if (n == INT32_MAX) cout << "$ ";
                else cout << n << " ";
            }
            cout << endl;
        }
        cout << "-------------------------" << endl;
    }
};