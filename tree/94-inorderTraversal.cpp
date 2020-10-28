/*
 * @Description: 二叉树的中序遍历
 * @Author: guchen
 * @Date: 2020-10-28 20:44:32
 * @LastEditTime: 2020-10-28 20:44:57
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
    // 复习
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        vector<int> res;
        while (cur != nullptr) {
            if (cur->left != nullptr) {
                TreeNode* node = cur->left;
                while (node->right != nullptr && node->right != cur) node = node->right;
                if (node->right == nullptr) {
                    node->right = cur;
                    cur = cur->left;
                } else {
                    res.push_back(cur->val);
                    node->right = nullptr;
                    cur = cur->right;
                }
            } else {
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }

    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top(); s.pop();
            if (node == nullptr) {
                node = s.top(); s.pop();
                res.push_back(node->val);
            } else {
                if (node->right != nullptr) s.push(node->right);
                s.push(node);
                s.push(nullptr);
                if (node->left != nullptr) s.push(node->left);
            }
        }
        return res;
    }

    vector<int> inorderTraversal1(TreeNode* root) {
          vector<int> res;
          dfs(root, res);
          return res;
    }
    void dfs(TreeNode* node, vector<int>& res) {
        if (node == nullptr) return;
        dfs(node->left, res);
        res.push_back(node->val);
        dfs(node->right, res);
    }
};