/*
 * @Description: 将有序数组转换为二叉搜索树
 * @Author: guchen
 * @Date: 2020-11-13 16:57:16
 * @LastEditTime: 2020-11-13 16:57:51
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toBST(nums, 0, nums.size() - 1);
    }

    TreeNode* toBST(vector<int>& nums, int s, int e) {
        if (s > e) return nullptr;
        int mid = s + (e - s) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = toBST(nums, s, mid - 1);
        root->right = toBST(nums, mid + 1, e);
        return root;
    }
};
