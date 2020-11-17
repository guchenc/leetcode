/*
 * @Description: 不同的二叉搜索树
 * @Author: guchen
 * @Date: 2020-11-17 19:15:30
 * @LastEditTime: 2020-11-17 19:17:13
 */
#include "../alg.h"
class Solution {
public:
    // 递归 + 记忆化(BST的结构数目只与节点数有关!!!)
    int numTrees(int n) {
        map<int, int> m;    // key: 节点数 val: BST结构种类
        return cnt(1, n, m);
    }

    int cnt(int l, int r, map<int, int>& m) {
        if (l >= r) return 1;
        auto it = m.find(r - l + 1);    // 注意放在这里的好处! 避免在循环中不断判断
        if (it != m.end()) return it->second;
        int total = 0;
        for (int i = l; i <= r; i++)
            total += cnt(l, i - 1, m) * cnt(i + 1, r, m);
        m[r - l + 1] = total;
        return total;
    }

    // 递归 + 记忆化
    int numTrees1(int n) {
        map<pair<int, int>, int> m; // 记忆化，保存每个区间序列可能构成的二叉搜索树数目
        return cnt1(1, n, m);
    }

    int cnt1(int l, int r, map<pair<int, int>, int>& m) {
        if (l >= r) return 1;
        int n = 0;
        for (int i = l; i <= r; i++) {
            int root = i;
            pair<int, int> lseq(l, root - 1), rseq(root + 1, r);
            if (m.find(lseq) == m.end()) m[lseq] = cnt1(l, root - 1, m);
            if (m.find(rseq) == m.end()) m[rseq] = cnt1(root + 1, r, m);
            n += m[lseq] * m[rseq];
        }
        return n;
    }
};
