/*
 * @Description: 单词接龙II
 * @Author: guchen
 * @Date: 2020-11-06 16:51:56
 * @LastEditTime: 2020-11-06 16:52:57
 */
#include "../alg.h"
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return res;
        unordered_map<string, set<string>> paths;
        unordered_set<string> sb, se, visited;
        sb.insert(beginWord);
        se.insert(endWord);
        int wlen = beginWord.size();
        int cnt = 0;
        while (!sb.empty() && !se.empty()) {
            auto& small = sb.size() > se.size() ? se : sb;
            auto& bigger = sb.size() > se.size() ? sb : se;
            bool reverse = small == se;
            unordered_set<string> next;
            for (auto it = small.begin(); it != small.end(); it++) {
                string cur = *it;
                string tmp = cur;
                for (auto n : small) visited.insert(n); // 这一步非常关键！！防止同层之间加入paths
                if (bigger.find(cur) != bigger.end()) {
                    // print(paths, beginWord);
                    // for (auto n : paths) {
                    //     cout << n.first << ":";
                    //     for (auto sd: n.second) cout << sd << " ";
                    //     cout << endl;
                    // }
                    vector<string> path = {beginWord};
                    generatePath(res, path, paths, endWord, beginWord, cnt);
                    return res;
                }
                for (int i = 0; i < wlen; i++) {
                   for (char c = 'a'; c <= 'z'; c++) {
                       tmp[i] = c;
                       if (tmp == cur) continue;
                       if (dict.find(tmp) == dict.end() || visited.find(tmp) != visited.end()) continue;
                       next.insert(tmp);
                       if (reverse) paths[tmp].insert(cur);
                       else paths[cur].insert(tmp);
                   }
                   tmp = cur; 
                }
            }
            small.swap(next);
            cnt++;
        }
        return res;
    }

    void generatePath(vector<vector<string>>& res, vector<string>& path,
                        unordered_map<string, set<string>>& next,
                        string& endWord, string& cur, int cnt) {
        if (cnt == 0 && cur == endWord) {
            res.push_back(path);
            return;
        }
        for (auto n : next[cur]) {
            path.push_back(n);
            generatePath(res, path, next, endWord, n, cnt - 1);
            path.pop_back();
        }
    }

    void print(unordered_map<string, set<string>>& next, string& beginWord) {
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string cur = q.front(); q.pop();
                cout << cur << " ";
                for (auto n : next[cur]) q.push(n);
            }
            cout << endl;
        }
    }
};