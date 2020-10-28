/*
 * @Description: 二叉树的前序遍历
 * @Author: guchen
 * @Date: 2020-10-28 21:07:24
 * @LastEditTime: 2020-10-28 21:07:50
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> seq;
        if (root == nullptr) return seq;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            seq.push_back(node->val);
            if (node->right != nullptr) s.push(node->right);
            if (node->left != nullptr) s.push(node->left);
        }
        return seq;
    }

    vector<int> preorderTraversal1(TreeNode* root) {
        vector<int> seq;
        dfs(seq, root);
        return seq;
    }

    void dfs(vector<int>& seq, TreeNode* root) {
        if (root == nullptr) return;
        seq.push_back(root->val);
        dfs(seq, root->left);
        dfs(seq, root->right);
    }
};