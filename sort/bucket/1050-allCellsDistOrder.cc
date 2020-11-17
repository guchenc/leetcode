/*
 * @Description: 距离顺序排列矩阵单元格
 * @Author: guchen
 * @Date: 2020-11-17 19:27:34
 * @LastEditTime: 2020-11-17 19:27:48
 */
#include "../alg.h"
class Solution {
public:
    // 桶排序 time:O(R*C) space: O(R*C)
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        vector<vector<vector<int>>> buckets(R + C + 1);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int dis = abs(i - r0) + abs(j - c0);
                buckets[dis].push_back({i, j});
            }
        }
        for (auto& bucket : buckets) {
            for (auto& it : bucket)
                res.push_back(move(it));
        }
        return res;
    }

    // 自定义快排方法 time: O(nlogn) space: O(logn) n = R*C
    vector<vector<int>> allCellsDistOrder2(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++)
                res.push_back({i, j});
        }
        sort(res.begin(), res.end(), [&](vector<int>& u, vector<int>& v) {
            int udis = abs(u[0] - r0) + abs(u[1] - c0);
            int vdis = abs(v[0] - r0) + abs(v[1] - c0);
            return udis < vdis;
        });
        return res;
    }
    // BFS time: O(R*C) space: O(R*C)
    vector<vector<int>> allCellsDistOrder1(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        queue<pair<int, int>> q;
        bool visited[101][101] = {false};
        // vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        q.push({r0, c0});
        visited[r0][c0] = true;
        res.push_back({r0, c0});
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int x = p.first, y = p.second;
            for (auto dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C || visited[nx][ny]) continue;
                q.push({nx, ny});
                visited[nx][ny] = true;
                res.push_back({nx, ny});
            }
        }
        return res;
    }
};
