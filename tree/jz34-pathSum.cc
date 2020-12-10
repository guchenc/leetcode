/*
 * @Description: 二叉树中和为某一值的路径
 * @Author: guchen
 * @Date: 2020-12-10 20:24:37
 * @LastEditTime: 2020-12-10 20:25:22
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
    // DFS + 回溯 time: O(n) space: O(n)
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, 0, sum, res, path);
        return res;
    }
    
    void dfs(TreeNode* root, int total, int sum, vector<vector<int>>& res, vector<int>& path) {
        if (root == nullptr) return;
        total += root->val; // 到达当前层时的路径和
        // 是叶子结点直接放入结果集，否则继续向下遍历，结点值可能为负  
        if (total == sum && root->left == nullptr && root->right == nullptr) {  
            path.push_back(root->val);
            res.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        dfs(root->left, total, sum, res, path);
        dfs(root->right, total, sum, res, path);
        path.pop_back();
    }

    
};