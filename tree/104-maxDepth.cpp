/*
 * @Description: 二叉树的最大深度
 * @Author: guchen
 * @Date: 2020-09-24 16:29:02
 * @LastEditTime: 2020-09-24 16:29:57
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
    int max_depth;

    // 层序遍历 每次取出一层 直至队列为空 time: O(n) space: O(n)
    int maxDepth(TreeNode* root) {
        int res = 0, layersize;
        queue<TreeNode*> q;
        if (root == nullptr)    return res;
        q.push(root);
        while (!q.empty()) {
            layersize = q.size();
            for (int i = 0; i < layersize; i++) {   // 每次取出一层
                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            res++;
        }
        return res;
    }

    // 递归 自底向上 time: O(n) space: O(1)
    int maxDepth2(TreeNode* root) {
        return down_top(root);
    }
    // 递归 自顶向下 time: O(n) space: O(1)
    int maxDepth1(TreeNode* root) {
        top_down(root, 0);
        return max_depth;
    }
    
    void top_down(TreeNode* root, int depth) {
        if (root == nullptr) {
            max_depth = max(max_depth, depth);
            return;
        }
        top_down(root->left, depth + 1);
        top_down(root->right, depth + 1);
    }

    int down_top(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int ldepth = down_top(root->left);
        int rdepth = down_top(root->right);
        return ldepth > rdepth ? ldepth + 1 : rdepth + 1;
    }
};