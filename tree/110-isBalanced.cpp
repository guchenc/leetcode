/*
 * @Description: 平衡二叉树
 * @Author: guchen
 * @Date: 2020-11-13 16:59:18
 * @LastEditTime: 2020-11-13 17:00:14
 */
#include "../alg.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // 自底向上
    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        int lh, rh;
        if ((lh = height(root->left)) == -1 
            || (rh = height(root->right)) == -1
            || abs(lh - rh) > 1) return -1;
        return max(lh, rh) + 1;
    }

    // 自顶向下
    bool isBalanced1(TreeNode* root) {
        if (root == nullptr) return true;
        return abs(height1(root->left) - height1(root->right)) <= 1 && isBalanced1(root->left) && isBalanced1(root->right);
    }

    int height1(TreeNode* root) {
        if (root == nullptr) return 0;
        int lh = height1(root->left);
        int rh = height1(root->right);
        return max(lh, rh) + 1;
    }
};