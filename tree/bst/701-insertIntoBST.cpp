/*
 * @Description: 二叉搜索树中的插入操作
 * @Author: guchen
 * @Date: 2020-10-04 18:46:01
 * @LastEditTime: 2020-10-04 18:46:45
 */

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

    // 迭代 time: O(n) space: O(1)
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        TreeNode* node = root;
        while (node != nullptr) {
            if (val > node->val) {
                if (node->right == nullptr) {
                    node->right = new TreeNode(val);
                    break;
                }
                node = node->right;
            } else {
                if (node->left == nullptr) {
                    node->left = new TreeNode(val);
                    break;
                }
                node = node->left;
            }
        }
        return root;
    }

    // 递归 time: O(n) space: O(n)
    TreeNode* insertIntoBST1(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        if (val > root->val) root->right = insertIntoBST(root->right, val);
        else root->left = insertIntoBST(root->left, val);
        return root;
    }
};