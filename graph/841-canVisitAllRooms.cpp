/*
 * @Description: 钥匙和房间
 * @Author: guchen
 * @Date: 2020-10-06 21:27:46
 * @LastEditTime: 2020-10-06 21:38:50
 */
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    // BFS
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        queue<int> q;
        int cnt = 0;
        q.push(0);
        visited[0] = true;  // 注意这里必须加入时就设置已访问，避免重复加入队列
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int cur = q.front(); q.pop();
                cnt++;
                for (int j = 0; j < rooms[cur].size(); j++) {
                    int next = rooms[cur][j];
                    if (visited[next])  continue;
                    q.push(next);
                    visited[next] = true;
                }
            }
            cout << endl;
        }
        return cnt == rooms.size();
    }

    // 将房间看作图中的节点，钥匙代表有向边!!!，能从房间0到往任意房间表明图是连通的，利用DFS遍历一遍图，用visited数组记录房间的到访情况
    bool canVisitAllRooms1(vector<vector<int>>& rooms) {
        // print_graph(rooms);
        int cnt = 1;
        vector<bool> visited(rooms.size(), false);   // 避免成环
        visited[0] = true;
        dfs(rooms, visited, 0, &cnt);
        return cnt == rooms.size();
    }

    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int cur, int* cnt) {
        for (auto child : rooms[cur]) {
            if (visited[child]) continue;
            (*cnt)++;
            visited[child] = true;
            dfs(rooms, visited, child, cnt);
        }
    }

    void print_graph(vector<vector<int>>& graph) {
        for (int i = 0; i < graph.size(); i++) {
            cout << "room: " << i << "[";
            for (int j = 0; j < graph[i].size(); j++) {
                cout << graph[i][j];
                if ((j + 1) != graph[i].size()) cout << ",";
            }
            cout << "]" << endl;
        }
    }
};