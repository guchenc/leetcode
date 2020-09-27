#include <vector>
#include <queue>
#include <iostream>
using namespace std;

void print(vector<vector<int>>& map) {
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[0].size(); j++) {
            if (map[i][j] == INT32_MAX) 
                cout << "* ";
            else if (map[i][j] == 0)
                cout << "$ ";
            else if (map[i][j] == -1)
                cout << "# ";
            else cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    void fillMap(vector<vector<int>>& map) {
        for (int i = 0; i < map.size(); i++) {
            for (int j = 0; j < map[0].size(); j++) {
                // if (map[i][j] != INT32_MAX) continue;
                // map[i][j] = findNearDoorFromRoom(map, i, j);
                if (map[i][j] != 0) continue;
                findNearDoorFromDoor(map, i, j);
            }
        }
    }

    void findNearDoorFromDoor(vector<vector<int>>& map, int i, int j) {
        queue<pair<int, int>> q;
        int nrow = map.size(), ncol = map[0].size();
        vector<pair<int, int>> direct = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int dis = -1;
        q.push({i, j});
        while (!q.empty()) {
            int layersz = q.size();
            for (int k = 0; k < layersz; k++) {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                dis = map[x][y] + 1;
                // map[x][y] = min(map[x][y], dis);
                for (auto d : direct) {
                    int nx = x + d.first, ny = y + d.second;
                    if (nx < 0 || nx >= nrow || ny < 0 || ny >= ncol || map[nx][ny] == -1 || map[nx][ny] == 0 || map[nx][ny] < dis) continue;
                    map[nx][ny] = min(dis, map[nx][ny]);
                    q.push({nx, ny});
                }
            }
        }
    }

    int findNearDoorFromRoom(vector<vector<int>>& map, int i, int j) {
        queue<pair<int, int>> q;
        int nrow = map.size(), ncol = map[0].size();
        vector<vector<bool>> visited(nrow, vector<bool>(ncol, false));
        vector<pair<int, int>> direct = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int dis = 0;
        q.push({i, j});
        while (!q.empty()) {
            int layersz = q.size();
            dis++;
            for (int k = 0; k < layersz; k++) {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                visited[x][y] = true;
                if (map[x][y] == 0)
                    return dis - 1;
                for (auto d : direct) {
                    int nx = x + d.first, ny = y + d.second;
                    if (nx < 0 || nx >= nrow || ny < 0 || ny >= ncol || visited[nx][ny]) continue;
                    if (map[nx][ny] != -1)
                        q.push({nx, ny});
                }
            }
        }
        return INT32_MAX;
    }

};

class Solution2 {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty()) return;
        const int INF = 2147483647;
        int m = rooms.size(), n = rooms[0].size();
        vector<pair<int, int>> directs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] != 0) continue;
                q.push(make_pair(i, j));
            }
        }
        while (!q.empty()) {
            print(rooms);
            cout << endl;
            getchar();
            auto pos = q.front();q.pop();
            int x = pos.first, y = pos.second;
            int dp = rooms[x][y] + 1; 
            for (auto d : directs) {
                int nx = x + d.first, ny = y + d.second;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || rooms[nx][ny] != INF) continue;
                rooms[nx][ny] = dp; 
                q.push(make_pair(nx, ny));
            }
        }
        return;
    }
};

int main() {
    vector<vector<int>> map = {
        {INT32_MAX, INT32_MAX, 0, -1, INT32_MAX, -1},
        {-1, INT32_MAX, 0, -1, INT32_MAX, INT32_MAX},
        {-1, -1, INT32_MAX, -1, INT32_MAX, INT32_MAX},
        {INT32_MAX, 0, INT32_MAX, INT32_MAX, -1, 0},
        {-1, INT32_MAX, -1, 0, INT32_MAX, INT32_MAX},
        {-1, -1, INT32_MAX, -1, -1, -1}
    };
    // Solution s;
    // s.fillMap(map);
    // print(map);

    Solution2 s2;
    s2.wallsAndGates(map);
    print(map);
    return 0;
}

