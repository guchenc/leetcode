/*
 * @Description: 删除二叉搜索树中的节点
 * @Author: guchen
 * @Date: 2020-11-12 20:20:14
 * @LastEditTime: 2020-11-12 20:20:37
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
    // 优雅的递归
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right = deleteNode(root->right,key);
        else {
            if (root->left != nullptr && root->right != nullptr) {  // 左右子树都不为空
                TreeNode* succ = root->right;
                while (succ->left != nullptr) succ = succ->left;    // 找到待删除节点的后继节点
                root->right = deleteNode(root->right, succ->val);   // 从右子树中删除后继节点
                root->val = succ->val;  // 使用后继节点替代待删除节点
            } else {
                return root->left == nullptr ? root->right : root->left;    // 左右子树至少一个为空
            }
        }
        return root;
    }

    // 恶心的迭代 
    TreeNode* deleteNode1(TreeNode* root, int key) {
        TreeNode* cur = root, *father = nullptr;
        bool isLeft = false;
        while (cur != nullptr) {
            if (key < cur->val) {
                father = cur;
                cur = cur->left;
                isLeft = true;
            } else if (key > cur->val) {
                father = cur;
                cur = cur->right;
                isLeft = false;
            } else {
                if (cur->left == nullptr && cur->right == nullptr) {
                    if (father == nullptr) return nullptr;
                    else {
                        if (isLeft) father->left = nullptr;
                        else father->right = nullptr;
                        break;
                    }
                } else if (cur->left != nullptr && cur->right != nullptr) {
                    TreeNode* succ = cur->right;
                    while (succ->left != nullptr) succ = succ->left;
                    cur->right = deleteMin(cur->right);
                    succ->left = cur->left;
                    succ->right = cur->right;
                    if (father == nullptr) {
                        return succ;
                    } else {
                        if (isLeft) father->left = succ;
                        else father->right = succ;
                    }
                    break;
                } else {
                    TreeNode* tmp = cur->left == nullptr ? cur->right : cur->left;
                    if (father == nullptr) return tmp;
                    else {
                        if (isLeft) father->left = tmp;
                        else father->right = tmp;
                    }
                    break;
                }
            }
        }
        return root;
    }

    TreeNode* deleteMin(TreeNode* root) {
        if (root == nullptr) return nullptr;
        if (root->left == nullptr) return root->right;
        TreeNode* cur = root->left, *prev = root;
        while (cur->left != nullptr) {
            prev = cur;
            cur = cur->left;
        }
        prev->left = cur->right == nullptr ? nullptr : cur->right;  
        return root;
    }
};