/*
 * @Description: 合并二茶树
 * @Author: guchen
 * @Date: 2020-09-23 18:46:32
 * @LastEditTime: 2020-09-23 18:47:06
 */
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // DFS(最优写法) time: O(n+m) space: O(1)
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr)  return t2;
        if (t2 == nullptr)  return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }

    // DFS 利用t1和t2的现有节点 time: O(n+m) space: O(1)
    TreeNode* mergeTrees2(TreeNode* t1, TreeNode* t2) {
        return dfs(t1, t2);
    }

    TreeNode* dfs(TreeNode* t1, TreeNode* t2) {
        TreeNode* node = nullptr;
        if (t1 == nullptr && t2 == nullptr)
            return nullptr;
        if (t1 == nullptr) {
            node = t2;
            node->left = dfs(nullptr, t2->left);
            node->right = dfs(nullptr, t2->right);
        } else if (t2 == nullptr){
            node = t1;
            node->left = dfs(t1->left, nullptr);
            node->right = dfs(t1->right, nullptr);
        } else {
            node = t1;
            node->val += t2->val;
            node->left = dfs(t1->left, t2->left);
            node->right = dfs(t1->right, t2->right);
        }
        return node;
        
    }

    // DFS 节点空间重新分配 time: O(n+m) space: O(1)
    TreeNode* mergeTrees1(TreeNode* t1, TreeNode* t2) {
        return dfs(t1, t2);
    }

    TreeNode* dfs1(TreeNode* t1, TreeNode* t2) {
        TreeNode* node = nullptr;
        if (t1 == nullptr && t2 == nullptr)
            return nullptr;
        if (t1 == nullptr) {
            node = new TreeNode(t2->val);
            node->left = dfs(nullptr, t2->left);
            node->right = dfs(nullptr, t2->right);
        } else if (t2 == nullptr){
            node = new TreeNode(t1->val);
            node->left = dfs(t1->left, nullptr);
            node->right = dfs(t1->right, nullptr);
        } else {
            node = new TreeNode(t1->val + t2->val);
            node->left = dfs(t1->left, t2->left);
            node->right = dfs(t1->right, t2->right);
        }
        return node;
    }
};