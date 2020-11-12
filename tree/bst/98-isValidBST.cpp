/*
 * @Description: 验证二叉搜索树
 * @Author: guchen
 * @Date: 2020-11-12 20:23:28
 * @LastEditTime: 2020-11-12 20:23:49
 */
#include "../alg.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* prev = nullptr;
    // 在递归中序遍历的过程中，判断中序序列是否满足递增序列 time: O(n) space: O(n)
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        bool lf = isValidBST(root->left);
        if (prev != nullptr && root->val <= prev->val) return false;
        prev = root;
        bool rf = isValidBST(root->right);
        return lf & rf;
    }

    // time: O(n) space: O(n)
    bool isValidBST2(TreeNode* root) {
        return dfs2(root, LONG_MIN, LONG_MAX);
    }

    bool dfs2(TreeNode* root, long lower, long upper) {
        if (root == nullptr) return true;
        if (root->val <= lower || root->val >= upper) return false;
        return dfs2(root->left, lower, root->val) && dfs2(root->right, root->val, upper);
    }

    // 若是BST，中序遍历结果必然是递增序列 time: O(n) space: O(n)
    bool isValidBST1(TreeNode* root) {
        vector<int> seq;
        dfs1(seq, root);
        int len = seq.size();
        for (int i = 0; i < len - 1; i++) {
            if (seq[i] >= seq[i + 1]) return false;
        }
        return true;
    }

    void dfs1(vector<int>& seq, TreeNode* root) {
        if (root == nullptr) return;
        dfs1(seq, root->left);
        seq.push_back(root->val);
        dfs1(seq, root->right);
    }
};