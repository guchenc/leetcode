/*
 * @Description: 树中距离之和
 * @Author: guchen
 * @Date: 2020-10-06 17:19:30
 * @LastEditTime: 2020-10-06 17:19:53
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> res;
    vector<vector<int>> tree;   // 临接表
    vector<int> nodecnt;
    int n;

    // 学会处理用边表示的图 time: O(n) space: O(n)
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        if (N == 0) return {};
        n = N;
        res.assign(N, 0);
        tree.assign(N, vector<int>());
        nodecnt.assign(N, 1);
        for (int i = 0; i < edges.size(); i++) {    // 通过给定边初始化临接表
            tree[edges[i][0]].emplace_back(edges[i][1]);
            tree[edges[i][1]].emplace_back(edges[i][0]);
        }
        dfs_cnt_nodes(0, -1);   // 递归遍历一遍树，计算以每个点为根的树所包含的节点数量(包括其自己)，同时计算了res[0]
        // print_nodes();
        dfs_cnt_dis(0, -1); // 递归便利一遍树，通过res[child] = res[parent] + (n - nodecnt[child]) - nodecnt[child]计算结果
        return res;
    }

    void dfs_cnt_nodes(int index, int parent) {
        int cnt = 1;
        for (int i = 0; i < tree[index].size(); i++) {
            int child = tree[index][i];
            if (child == parent) continue;
            dfs_cnt_nodes(child, index);
            cnt += nodecnt[child];
            res[index] += res[child] + nodecnt[child];  // 只是为了计算res[0]
        }
        nodecnt[index] = cnt;
    }

    void dfs_cnt_dis(int index, int parent) {
        for (int i = 0; i < tree[index].size(); i++) {
            int child = tree[index][i];
            if (child == parent) continue;
            res[child] = res[index] + (n - nodecnt[child]) - nodecnt[child];
            dfs_cnt_dis(child, index);
        }
    }

    void print_nodes() {
        for (int i = 0; i < tree.size(); i++) {
            cout << "node " << i << "(" << nodecnt[i] << "): ";
            for (int j = 0; j < tree[i].size(); j++) {
                cout << tree[i][j] << " ";
            }
            cout << endl;
        }
    }

};