/*
 * @Description:  路径总和II
 * @Author: guchen
 * @Date: 2020-09-26 19:17:18
 * @LastEditTime: 2020-09-27 11:20:43
 */
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> res;
    vector<int> ans;
    unordered_map<TreeNode*, TreeNode*> fathermap;

    // 迭代 time: O(n^2) space: O(n)
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        queue<TreeNode*> q_node;
        queue<int> q_sum;
        if (root == nullptr) return res;
        q_node.push(root);
        q_sum.push(root->val);
        fathermap[root] = nullptr;
        while (!q_node.empty()) {
            TreeNode* node = q_node.front(); q_node.pop();
            int total = q_sum.front(); q_sum.pop();
            if (node->left == nullptr && node->right == nullptr && total == sum) {
                get_path(node);
                res.push_back(ans);
            }
            if (node->right != nullptr) {
                q_node.push(node->right);
                fathermap[node->right] = node;
                q_sum.push(total + node->right->val);
            }
            if (node->left != nullptr) {
                q_node.push(node->left);
                fathermap[node->left] = node;
                q_sum.push(total + node->left->val);
            }
        }
        return res;
    }

    void get_path(TreeNode* node) {
        ans.clear();
        TreeNode* p = node;
        while (p != nullptr) {
            ans.push_back(p->val);
            p = fathermap[p];
        }
        reverse(ans.begin(), ans.end());
    }

    // DFS 回溯 time: O(n^2) space: O(n)
    vector<vector<int>> pathSum1(TreeNode* root, int sum) {
        dfs(root, sum);
        return res;
    }

    void dfs(TreeNode* root, int sum) {
        if (root == nullptr) return;
        ans.push_back(root->val);
        sum -= root->val;
        if (root->left == nullptr && root->right == nullptr && sum == 0)
            res.push_back(ans);
        dfs(root->left, sum);
        dfs(root->right, sum);
        ans.pop_back();
    }
};