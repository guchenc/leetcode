/*
 * @Description: 二叉搜索树的最小绝对差
 * @Author: guchen
 * @Date: 2020-10-12 05:50:18
 * @LastEditTime: 2020-10-12 05:51:15
 */
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 递归-中序遍历 time: O(n) space: O(n)
    int getMinimumDifference(TreeNode* root) {
        int prev = -1, minabs = INT32_MAX;
        dfs(root, prev, minabs);
        return minabs;
    }

    void dfs(TreeNode* root, int& prev, int& minabs) {
        if (root == nullptr) return;
        dfs(root->left, prev, minabs);
        if (prev == -1) prev = root->val;
        else {
            minabs = min(minabs, root->val - prev);
            prev = root->val;
        }
        dfs(root->right, prev, minabs);
    }

    // 迭代-中序遍历(Morris) time: O(n) space: O(1)
    int getMinimumDifference2(TreeNode* root) {
        TreeNode* cur = root;
        int minabs = INT32_MAX, prev = -1;
        while (cur != nullptr) {
            if (cur->left != nullptr) {
                TreeNode* pred = cur->left;
                while (pred->right != nullptr && pred->right != cur) pred = pred->right;
                if (pred->right == nullptr) {
                    pred->right = cur;
                    cur = cur->left;
                } else {
                    minabs = min(minabs, cur->val - prev);
                    prev = cur->val;
                    pred->right = nullptr;
                    cur = cur->right;
                }
            } else {
                if (prev != -1) minabs = min(minabs, cur->val - prev);
                prev = cur->val;
                cur = cur->right;
            }
        }
        return minabs;
    }

    // 递归 time: O(n) space: O(n)
    int getMinimumDifference1(TreeNode* root) {
        int minabs = INT32_MAX;
        if (root == nullptr) return minabs;
        TreeNode* pred = root->left, *succ = root->right;
        if (pred == nullptr && succ == nullptr) return minabs;
        if (pred != nullptr) {
            while (pred->right != nullptr) pred = pred->right;
            minabs = min(root->val - pred->val, minabs);
        } 
        if (succ != nullptr) {
            while (succ->left != nullptr) succ = succ->left;
            minabs = min(succ->val - root->val, minabs);
        } 
        int childmin = min(getMinimumDifference(root->left), getMinimumDifference(root->right));
        return min(minabs, childmin);
    }
};