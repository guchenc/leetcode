/*
 * @Description: 
 * @Author: guchen
 * @Date: 2020-10-06 18:21:11
 * @LastEditTime: 2020-10-06 18:21:51
 */
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // DFS time: O(n) space: O(n)
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int nrow = image.size(), ncol = image[0].size();
        // vector<vector<bool>> visited(nrow, vector<bool>(ncol, false)); 可以通过传递initcolor省略
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }

    void dfs(vector<vector<int>>& image, int x, int y, int initColor, int newColor) {
        if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != initColor || image[x][y] == newColor) return;
        image[x][y] = newColor;
        dfs(image, x - 1, y, initColor, newColor);
        dfs(image, x + 1, y, initColor, newColor);
        dfs(image, x, y - 1, initColor, newColor);
        dfs(image, x, y + 1, initColor, newColor);
        // if (x - 1 >= 0 && image[x][y] == initColor && !visited[x][y]) dfs(image, visited, x - 1, y, initColor, newColor);
        // if (x + 1 < image.size() && image[x][y] == initColor && !visited[x][y]) dfs(image, visited, x + 1, y, initColor, newColor);
        // if (y - 1 >= 0 && image[x][y] == initColor && !visited[x][y]) dfs(image, visited, x, y - 1, initColor, newColor);
        // if (y + 1 < image[0].size() && image[x][y] == initColor && !visited[x][y]) dfs(image, visited, x, y + 1, initColor, newColor);
    }

    // BFS 迭代 time: O(n) space: O(n)
    vector<vector<int>> floodFill1(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int, int>> q;
        int nrow = image.size(), ncol = image[0].size();
        vector<vector<bool>> visited(nrow, vector<bool>(ncol, false)); 
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int initcolor = image[sr][sc];
        q.push({sr, sc});
        while (!q.empty()) {
            int cnt = q.size();
            for (int i = 0; i < cnt; i++) {
                auto pos = q.front(); q.pop();
                int x = pos.first, y = pos.second;
                image[x][y] = newColor;
                visited[x][y] = true;
                for (auto d : dir) {
                    int nx = x + d.first, ny = y + d.second;
                    if (nx < 0 || nx >= nrow || ny < 0 || ny >= ncol || image[nx][ny] != initcolor || visited[nx][ny]) continue;
                    q.push({nx, ny});
                }
            }
        }
        return image;
    }
    
};