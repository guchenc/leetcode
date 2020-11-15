/*
 * @Description: 不同的二叉搜索树
 * @Author: guchen
 * @Date: 2020-11-15 18:28:35
 * @LastEditTime: 2020-11-15 18:29:39
 */
#include "../alg.h"
class Solution {
public:
    int numTrees(int n) {
        map<pair<int, int>, int> m; // 不能使用unordered_map因为没有定义哈希函数
        return help(1, n, m);
    }

    int help(int l, int r, map<pair<int, int>, int>& m) {
        if (l >= r) return 1;
        int cnt = 0;
        for (int i = l; i <= r; i++) {
            if (m.find({l, i - 1}) == m.end()) m[{l, i - 1}] = help(l, i - 1, m);
            if (m.find({i + 1, r}) == m.end()) m[{i + 1, r}] = help(i + 1, r, m);
            cnt += m[{l, i - 1}] * m[{i + 1, r}];
        }
        m[{l, r}] = cnt;
        return cnt;
    }

    int numTrees1(int n) {
        vector<vector<int>> mem(n + 2, vector<int>(n + 2, -1));
        return test(1, n, mem);
    }

    int test(int begin, int end, vector<vector<int>>& mem) {
        if (begin >= end) return 1;
        int cnt = 0;
        for (int i = begin; i <= end; i++) {    // 取区间范围内的每个点作为根
            // cout << "mid:" << i << " [" << begin << ", " << i - 1 << "] " << "[" << i + 1 << ", " << end << "]" << endl;
            if (mem[begin][i - 1] == -1) mem[begin][i - 1] = test(begin, i - 1, mem);
            if (mem[i + 1][end] == -1) mem[i + 1][end] = test(i + 1, end, mem);
            cnt += mem[begin][i - 1] * mem[i + 1][end];
        }
        mem[begin][end] = cnt;
        // cout << "[" << begin << ", " << end << "] : " << cnt << endl; 
        return cnt;
    }
};