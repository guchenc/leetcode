/*
 * @Description: 二叉搜索树迭代器
 * @Author: guchen
 * @Date: 2020-11-12 20:22:01
 * @LastEditTime: 2020-11-12 20:22:30
 */
#include "../alg.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 // 受控递归，均摊分析
class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        push_leftmost(root);
    }
    
    void push_leftmost(TreeNode* root) {
        while (root != nullptr) {
            s.push(root);
            root = root->left;
        }
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = s.top(); s.pop();
        int res = node->val;
        push_leftmost(node->right);
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */