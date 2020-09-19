/*
 * @Description: 左叶子之和
 * @Author: guchen
 * @Date: 2020-09-19 15:20:05
 * @LastEditTime: 2020-09-19 16:12:16
 */
#include <iostream>
#include <queue>
#include <set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 迭代 time: O(n) space: O(n)
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> q;
        if (!root)
            return 0;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left != nullptr) {
                if (!node->left->left && !node->left->right)
                    sum += node->left->val;
                else 
                    q.push(node->left);
            }
            if (node->right != nullptr)
                q.push(node->right);
        }
        return sum;
    }

    // 迭代 time: O(n) space: O(n)
    int sumOfLeftLeaves2(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> q;
        set<TreeNode*> s;   // 存放左子树的根
        if (!root)
            return 0;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
                s.insert(node->left);
            }
            if (node->right)
                q.push(node->right);
            if (!node->left && !node->right)
                if (s.find(node) != s.end()) sum += node->val;
        }
        return sum;
    }
    // DFS time: O(n) space: O(1)
    int sumOfLeftLeaves1(TreeNode* root) {
        return dfs(root, false);
    }

    int dfs(TreeNode* root, bool isLeft) {
        if (!root)
            return 0;
        if (isLeft && !root->left && !root->right)  // 只有递归到左叶子节点时返回其值，其余情况递归到叶节点后返回0
            return root->val;
        return dfs(root->left, true) + dfs(root->right, false);
    }
};