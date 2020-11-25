/*
 * @Description: 完全二叉树的节点个数
 * @Author: guchen
 * @Date: 2020-11-25 15:17:10
 * @LastEditTime: 2020-11-25 15:17:46
 */
#include "../alg.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 满二叉树：它是一棵空树或者它的叶子节点只出在最后两层，若最后一层不满则叶子节点只在最左侧，满二叉树的左右子树也都是满二叉树
    int countNodes(TreeNode* root) {
        int n = 0;
        while (root != nullptr) {
            int lh = getDepth(root->left);
            int rh = getDepth(root->right);
            if (lh == rh) {
                root = root->right;
                n += pow(2, lh);
            } else {
                root = root->left;
                n += pow(2, rh);
            } 
        }
        return n;
    }

    int getDepth(TreeNode* root) {
        int height = 0;
        while (root != nullptr) {
            height++;
            root = root->left;
        }
        return height;
    }
};