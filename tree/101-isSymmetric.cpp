/*
 * @Description: 对称二叉树
 * @Author: guchen
 * @Date: 2020-09-24 17:53:29
 * @LastEditTime: 2020-10-22 15:55:51
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
        vector<int> vals;
        q.push(root);
        vals.push_back(root->val);
        while (!q.empty()) {
            int size = vals.size();
            int l = 0, r = size - 1;
            while (l < r) {
                if (vals[l] != vals[r]) return false;
                l++, r--;
            }
            vals.clear();
            size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front(); q.pop();
                if (temp->left != nullptr) {
                    q.push(temp->left);
                    vals.push_back(temp->left->val);
                } else vals.push_back(INT_MAX);
                if (temp->right != nullptr) {
                    q.push(temp->right);
                    vals.push_back(temp->right->val);
                } else vals.push_back(INT_MAX);
            }
        }
        return true;
    }

    bool isSymmetric1(TreeNode* root) {
        if (root == nullptr) return true;
        return symmetric(root->left, root->right);
    }

    bool symmetric(TreeNode* n1 ,TreeNode* n2) {
        if (n1 == nullptr && n2 == nullptr) return true;
        if (n1 == nullptr || n2 == nullptr) return false;
        if (n1->val != n2->val) return false;
        return symmetric(n1->left, n2->right) && symmetric(n1->right, n2->left);
    }

    // 迭代 time: O(n) space: O(n)
    bool isSymmetric(TreeNode* root) { 
        queue<TreeNode*> q;
        if (root == nullptr) return true;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode* r1 = q.front();
            q.pop();
            TreeNode* r2 = q.front();
            q.pop();
            if (r1 == nullptr && r2 == nullptr)
                continue;
            if ((r1 != nullptr && r2 == nullptr) || (r1 == nullptr && r2 != nullptr))
                return false;
            if (r1->val != r2->val)
                return false;
            q.push(r1->left);
            q.push(r2->right);
            q.push(r1->right);
            q.push(r2->left);
        }
        return true;

    }

    // 递归 time: O(n) space: O(n) 使用递归时需要考虑栈上空间
    bool isSymmetric1(TreeNode* root) {
        return isMirror(root, root);
    }

    bool isMirror(TreeNode* r1, TreeNode* r2) {
        if (r1 == nullptr && r2 == nullptr)
            return true;
        if (r1 == nullptr || r2 == nullptr)
            return false;
        return (r1->val == r2->val) && isMirror(r1->left, r2->right) && isMirror(r1->right, r2->left);
    }
};