/*
 * @Description: 不同的二叉搜索树 II
 * @Author: guchen
 * @Date: 2020-11-17 19:12:17
 * @LastEditTime: 2020-11-17 19:15:00
 */
#include "../alg.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generate(1, n);
    }
    
    vector<TreeNode*> generate(int l, int r) {
        if (l > r) return {nullptr};
        vector<TreeNode*> roots, lchilds, rchilds;
        for (int i = l; i <= r; i++) {  // 选择i作为子BST的根节点
            // TreeNode* root = new TreeNode(i); 注意不能在这里创建node!!!
            lchilds = generate(l, i - 1);  // 所有可能的左BST
            rchilds = generate(i + 1, r);  // 所有可能的右BST
            for (auto& lchild : lchilds) {
                for (auto& rchild : rchilds) {
                    TreeNode* root = new TreeNode(i);   // 应该在这里创建!!!
                    root->left = lchild;
                    root->right = rchild;
                    roots.push_back(root);
                }
            }
        }
        return roots;
    }

};
