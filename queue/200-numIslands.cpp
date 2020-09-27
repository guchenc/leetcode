/*
 * @Description: 岛屿数量
 * @Author: guchen
 * @Date: 2020-09-27 14:58:28
 * @LastEditTime: 2020-09-27 15:00:51
 */
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    // 递归实现DFS time: O(n*m)  space: O(n*m) 最坏情况: 整个网格都是陆地
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())  return 0;
        int cnt = 0, nrow = grid.size(), ncol = grid[0].size();
        for (int i = 0; i < nrow; i++) {
            for (int j = 0; j < ncol; j++) {
                if (grid[i][j] == '0')
                    continue;
                dfs(grid, nrow, ncol, i, j);
                cnt++;
            }
        }
        return cnt;
    }

    void dfs(vector<vector<char>>& grid, int nrow, int ncol, int x, int y) {
        if (x < 0 || x >= nrow || y < 0 || y >= ncol || grid[x][y] == '0')  return;
        grid[x][y] = '0';   // 已访问过的陆地被置为水，改变了grid
        dfs(grid, nrow, ncol, x - 1, y);
        dfs(grid, nrow, ncol, x + 1, y);
        dfs(grid, nrow, ncol, x, y - 1);
        dfs(grid, nrow, ncol, x, y + 1);
    }

    // 借助队列进行BFS
    int numIslands1(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int nrow = grid.size(), ncol = grid[0].size();
        int cnt = 0, layersz = 0;
        // 可以通过将访问过的陆地置为'$'，省去visited占用的内存，缺点是会修改grid
        vector<vector<bool>> visited(nrow, vector<bool>(ncol, false));
        for (int i = 0; i < nrow; i++) {
            for (int j = 0; j < ncol; j++) {
                if (visited[i][j] || grid[i][j] == '0') continue;
                flood(grid, visited, i, j); // 填充该陆地所属岛屿
                cnt++;
            }
        }
        return cnt;
    }

    void flood(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        vector<pair<int,int>> direct = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int nrow = grid.size(), ncol = grid[0].size();
        queue<pair<int,int>> q;
        q.push({x, y});
        visited[x][y] = true;
        while (!q.empty()) {
            auto pos = q.front(); q.pop();
            int x = pos.first, y = pos.second;
            for (auto d : direct) {
                int nx = x + d.first, ny = y + d.second;
                if (nx < 0 || nx >= nrow || ny < 0 || ny >= ncol || visited[nx][ny] || grid[nx][ny] == '0')
                    continue;
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
            // print_grid(grid, visited, x, y);
            // cout << endl;
        }
    }

    void print_grid(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        int nrow = grid.size(), ncol = grid[0].size();
        for (int i = 0; i < nrow; i++) {
            for (int j = 0; j < ncol; j++) {
                if (i == x && j == y)
                    cout << "$ ";
                else if (visited[i][j]) {
                    cout << "* ";
                } else {
                    cout << grid[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
};