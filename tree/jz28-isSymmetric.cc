/*
 * @Description: 对称的二叉树
 * @Author: guchen
 * @Date: 2020-12-10 20:25:47
 * @LastEditTime: 2020-12-10 20:26:12
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode*> q;
        vector<TreeNode*> layer;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
                layer.push_back(node->left);
                layer.push_back(node->right);
            }
            int l = 0, r = layer.size() - 1;
            while (l < r) {
                if (layer[l] == nullptr && layer[r] == nullptr) {
                    l++; r--;
                    continue;
                }
                if (layer[l] == nullptr || layer[r] == nullptr) return false;;
                if (layer[l]->val != layer[r]->val) return false;
                l++; r--;
            }
            layer.clear();
        }
        return true;
    }

    // 递归 time: O(n) space: O(logn)
    bool isSymmetric1(TreeNode* root) {
        if (root == nullptr) return true;
        return helper(root->left, root->right);
    }

    bool helper(TreeNode* l, TreeNode* r) {
        if (l == nullptr && r == nullptr) return true;
        if (l == nullptr || r == nullptr) return false;
        return l->val == r->val && helper(l->left, r->right) && helper(l->right, r->left);
    }
};