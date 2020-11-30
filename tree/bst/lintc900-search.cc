/*
 * @Description: 二叉搜索树中最接近的值
 * @Author: guchen
 * @Date: 2020-11-29 15:20:38
 * @LastEditTime: 2020-11-29 15:21:40
 */
#include "../alg.h"

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        int res = 0;
        search(root, target, res);
        return res;
    }
    
    void search(TreeNode* root, double target, int& cur) {
        if (root == nullptr) return;
        cur = abs(root->val - target) < abs(cur - target) ? root->val : cur;
        if (root->val  == target) return;
        else if (root->val > target) {
            search(root->left, target, cur);
        } else if (root->val < target) {
            search(root->right, target, cur);
        }
    }
};