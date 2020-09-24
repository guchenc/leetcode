/*
 * @Description: 对称二叉树
 * @Author: guchen
 * @Date: 2020-09-24 17:53:29
 * @LastEditTime: 2020-09-24 17:54:09
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