/*
 * @Description: 验证二叉搜索树
 * @Author: guchen
 * @Date: 2020-10-22 15:56:45
 * @LastEditTime: 2020-10-22 15:57:05
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
    // time: O(n) space: O(n)
    bool isValidBST(TreeNode* root) {
        TreeNode *cur = root;
        if (root == nullptr) return true;
        if (root->left != nullptr) {    // 验证前继节点值小于当前节点
            cur = root->left;
            while (cur->right != nullptr) cur = cur->right;
            if (cur->val >= root->val) return false;
        }
        if (root->right != nullptr) {   // 验证后继节点值大于当前节点
            cur = root->right;
            while (cur->left != nullptr) cur = cur->left;
            if (cur->val <= root->val) return false;
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }

    // time: O(n) space: O(n)
    bool flag = false;
    bool isValidBST1(TreeNode* root) {
        int val;
        return dfs(root, val);
    }

    bool dfs(TreeNode* root, int& prev) {
        if (root == nullptr) return true;
        bool lflag = dfs(root->left, prev);
        if (flag && root->val <= prev) return false;
        prev = root->val;
        if (!flag) flag = true;
        bool rflag = dfs(root->right, prev);
        return lflag && rflag;
    }

};