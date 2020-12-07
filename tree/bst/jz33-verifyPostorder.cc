/*
 * @Description: 二叉搜索树的后序遍历序列
 * @Author: guchen
 * @Date: 2020-12-06 13:45:22
 * @LastEditTime: 2020-12-06 13:45:51
 */
#include "../../alg.h"
class Solution {
public:
    // 递归 利用BST的性质和后序遍历序列的特点 time: O(n) space: O(n)
    // 1 3 2 | 6 | [5]  后序遍历：最后一个元素为树的根节点
    // 左后续 右后续 根节点
    bool verifyPostorder(vector<int>& postorder) {
        return check(postorder, 0, postorder.size() - 1);
    }

    bool check(vector<int>& postorder, int l, int r) {
        if (l >= r) return true;
        int i = l;
        while (postorder[i] < postorder[r]) i++;    // 找到第一个大于根节点r的元素m，同时表明[l, m - 1]都小于根节点
        int m = i;
        while (postorder[i] > postorder[r]) i++;    // 确保[m, r - 1]都大于跟节点r
        return i == r && check(postorder, l, m - 1) && check(postorder, m, r - 1);
    }

    bool check1(vector<int>& postorder, int l, int r) {
        if (l >= r) return true;
        int m = -1;
        for (int i = l; i < r; i++) {
            if (m == -1 && postorder[i] > postorder[r]) m = i;
            if (m != -1 && postorder[i] < postorder[r]) return false;
        }
        if (m == -1) m = r;
        return check1(postorder, l, m - 1) && check1(postorder, m, r - 1);
    }


};