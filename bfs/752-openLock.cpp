/*
 * @Description: 打开转盘锁
 * @Author: guchen
 * @Date: 2020-09-28 21:19:54
 * @LastEditTime: 2020-09-29 11:49:22
 */
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 本质: 最短路径问题
    // 将锁的所有状态(不包括死锁)想象为图上的点，每个点与至多8个点(与当前节点表示的状态只有一位不同，不同的位距离为1)临接
    // 求初始状态"0000"到目标状态的最短路径
    
    // 双向BFS
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> s1, s2;
        unordered_set<string> visited;
        int step = 0;
        visited.insert(deadends.begin(), deadends.end());
        if (visited.find("0000") != visited.end()) return -1;
        s1.insert("0000");
        s2.insert(target);
        while (!s1.empty() && !s2.empty()) {
            // if (s1.size() > s2.size()) s1.swap(s2);
            auto& s = s1.size() > s2.size() ? s2 : s1;
            auto& b = s1.size() > s2.size() ? s1 : s2;
            unordered_set<string> next;
            for (auto it = s.begin(); it != s.end(); it++) {
                string cur = *it;
                if (visited.find(cur) != visited.end()) continue;   // 用来判断是不是死锁的
                if (b.find(cur) != b.end()) return step;    // 两个哈希表出现交集
                visited.insert(cur);  // 注意添加到visited的时机，否则两哈希表永不相交
                string temp = cur;
                for (int i = 0; i < 4; i++) {
                    char c = temp[i];
                    temp[i] = '0' + (c - '0' + 1) % 10;
                    if (visited.find(temp) == visited.end()) next.insert(temp);
                    temp[i] = '0' + (c - '0' + 10 - 1) % 10;
                    if (visited.find(temp) == visited.end()) next.insert(temp);
                    temp[i] = c;
                }
            }
            s = next;
            step++;
        }
        return -1;
    }

    // BFS求最短路径 time space
    int openLock1(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_set<string> visited;
        unordered_map<string, string> path;
        int step = 0;
        visited.insert(deadends.begin(), deadends.end());
        if (visited.find("0000") != visited.end()) return -1;
        q.push("0000");
        visited.insert("0000");
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front(); q.pop();
                string temp = cur;
                if (cur == target) {
                    // print_path(path, target);
                    return step;
                }
                for (int i = 0; i < 4; i++) {
                    char c = temp[i];
                    temp[i] = '0' + (c - '0' + 1) % 10;
                    if (visited.find(temp) == visited.end()) {
                        visited.insert(temp);
                        path.insert({temp, cur});
                        q.push(temp);
                    }
                    temp[i] = '0' + (c - '0' + 10 - 1) % 10;
                    if (visited.find(temp) == visited.end()) {
                        visited.insert(temp);
                        path.insert({temp, cur});
                        q.push(temp);
                    } 
                    temp[i] = c;
                }
            }
            step++;
        }
        return -1;
    }

    // 最短路径
    void print_path(unordered_map<string, string>& paths, string target) {
        vector<string> path;
        path.push_back(target);
        string s = target;
        auto it = paths.find(s);
        while (it != paths.end()) {
            path.push_back(it->second);
            it = paths.find(it->second);
        }
        reverse(path.begin(), path.end());
        for (auto it = path.begin(); it != path.end(); it++) {
            cout << *it;
            if (it + 1 != path.end()) cout << " -> ";
        }
        cout << endl;
    }
};