/*
 * @Description: 二叉搜索树的最近公共祖先
 * @Author: guchen
 * @Date: 2020-09-27 10:19:10
 * @LastEditTime: 2020-09-27 10:19:38
 */
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 该题中树为BST，它与普通二叉树(lc236)的区别是该树可以快速确定根节点到某个特定节点的路径
// 关键点: p q节点一定存在，那么根节点一定是两者的共同祖先
class Solution {
public:
    // 一次遍历(最优解) time: O(n) space: O(1)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = nullptr;
        TreeNode* node = root;
        while (node != nullptr) {
            if (p->val < node->val && q->val < node->val)
                node = node->left;
            else if (p->val > node->val && q->val > node->val)
                node = node->right;
            else {
                res = node;
                break;
            }
        }
        return res;
    }

    // 利用BST树可以快速确定根节点到某个特定节点路径的特性
    // time: O(n) space: O(n)
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_fathers, q_fathers;
        dfs(root, p, p_fathers);
        dfs(root, q, q_fathers);
        int i, bound = min(p_fathers.size(), q_fathers.size());
        for (i = 0; i < bound; i++) {
            if (p_fathers[i] != q_fathers[i])
                break;
        }
        return p_fathers[i - 1];
    }

    // 确定BST树从根节点到指定节点的路径
    void dfs(TreeNode* node, TreeNode* target, vector<TreeNode*>& fathers) {
        if (node == nullptr) return;
        fathers.push_back(node);
        if (target->val == node->val) return;
        if (target->val > node->val)
            dfs(node->right, target, fathers);
        else
            dfs(node->left, target, fathers);
    }
    
    

    // 递归 time: O(n) space: O(n)
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = nullptr;
        dfs1(root, p, q, res);
        return res;
    }

    // 子问题: 左右子树包含p或者q(包括根节点为节点的情况)
    bool dfs1(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode*& res) {
        if (node == nullptr) return false;
        bool lchild = dfs1(node->left, p, q, res);
        bool rchild = dfs1(node->right, p, q, res);
        if ((lchild && rchild) || ((node == p || node == q) && (lchild || rchild))) 
            res = node; // 只在最近公共祖先节点处执行
        return node == p || node == q || lchild || rchild;
    }
};