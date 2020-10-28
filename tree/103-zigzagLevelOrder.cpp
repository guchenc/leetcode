/*
 * @Description: 二叉树的锯齿形层次遍历
 * @Author: guchen
 * @Date: 2020-10-28 20:42:17
 * @LastEditTime: 2020-10-28 20:42:51
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        bool reverse = false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> layer(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                if (reverse) layer[size - 1 - i] = node->val;
                else layer[i] = node->val;
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            reverse = !reverse;
            res.push_back(move(layer));
        }
        return res;
    }
};