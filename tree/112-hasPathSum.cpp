/*
 * @Description: 
 * @Author: guchen
 * @Date: 2020-09-24 18:39:44
 * @LastEditTime: 2020-09-24 18:42:00
 */
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    // BFS time: O(n) space: O(n)
    bool hasPathSum(TreeNode* root, int sum) {
        queue<TreeNode*> node_q;
        queue<int> sum_q;
        if (root == nullptr) return false;
        node_q.push(root);
        sum_q.push(root->val);
        while (!node_q.empty()) {
            TreeNode* node = node_q.front(); node_q.pop();
            int total = sum_q.front(); sum_q.pop();
            if (node->left == nullptr && node->right == nullptr && total == sum)
            return true;
            if (node->left != nullptr) {
                node_q.push(node->left);
                sum_q.push(node->left->val + total);
            }
            if (node->right != nullptr) {
                node_q.push(node->right);
                sum_q.push(node->right->val + total);
            }
        }
        return false;
    }

    // 递归DFS 自顶向下 time: O(n) space: O(n)
    bool hasPathSum1(TreeNode* root, int sum) {
        return top_down(root, sum, 0);
    }

    bool top_down(TreeNode* root, int sum, int total) {
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr) {
            if (total + root->val == sum) return true;
            return false;
        }
        total += root->val;
        return top_down(root->left, sum, total) || top_down(root->right, sum , total);
    }

};