/*
 * @Description: 锟斤拷叶锟斤拷之锟斤拷
 * @Author: guchen
 * @Date: 2020-09-19 15:20:05
 * @LastEditTime: 2020-09-24 15:37:13
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
    // 锟斤拷锟斤拷 time: O(n) space: O(n)
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

    // 锟斤拷锟斤拷 time: O(n) space: O(n)
    int sumOfLeftLeaves2(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> q;
        set<TreeNode*> s;   // 锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷母锟�
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
        if (isLeft && !root->left && !root->right)  // 只锟叫递归到锟斤拷叶锟接节碉拷时锟斤拷锟斤拷锟斤拷值锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷莨榈揭讹拷诘锟襟返伙拷0
            return root->val;
        return dfs(root->left, true) + dfs(root->right, false);
    }
};