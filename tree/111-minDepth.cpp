/*
 * @Description: 二叉树的最小深度
 * @Author: guchen
 * @Date: 2020-09-28 22:24:43
 * @LastEditTime: 2020-09-28 22:25:26
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
    int minDepth(TreeNode* root) {
        int depth = 0, layersz = 0;
        queue<TreeNode*> q;
        if (root == nullptr) return 0;
        q.push(root);
        while (!q.empty()) {
            layersz = q.size();
            depth++;
            for (int i = 0; i < layersz; i++) {
                TreeNode* node = q.front(); q.pop();
                if (node->left == nullptr && node->right == nullptr) return depth;
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
        }
        return depth;
    }
};