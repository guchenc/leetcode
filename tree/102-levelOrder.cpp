/*
 * @Description: 二叉树的层序遍历
 * @Author: guchen
 * @Date: 2020-09-24 15:55:45
 * @LastEditTime: 2020-09-24 15:57:41
 */
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 不借助dummy time: O(n) space: O(n)
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        int layersize;
        if (root == nullptr)    return res;
        q.push(root);
        while (!q.empty()) {
            layersize = q.size();
            vector<int> layer;
            for (int i = 0; i < layersize; i++) {
                TreeNode* node = q.front();
                q.pop();
                layer.push_back(node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            res.push_back(layer);
        }
        return res;
    }
    // 创建dummy node用于区分各层 time: O(n) space: O(n)
    vector<vector<int>> levelOrder1(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> layer;
        queue<TreeNode*> q;
        if (root == nullptr)
           return res;
        TreeNode dummy(0); // 用作每层之间的分隔节点  3 d 9 20 d 15 7 (d 最后一层不需要)
        q.push(root);
        q.push(&dummy);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node != &dummy) {
                layer.push_back(node->val);
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            } else {
                res.push_back(layer);   // push_back是拷贝么？
                layer.clear();
                if (!q.empty()) // 如果此时队列还不为空，将dummy入队
                    q.push(&dummy);
            }
        }
        return res;
    }
};