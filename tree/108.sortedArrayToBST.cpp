/*
 * @Description: 将有序数组转换为二叉搜索树
 * @Author: guchen
 * @Date: 2020-10-22 15:59:05
 * @LastEditTime: 2020-10-22 15:59:30
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
        return createBST(nums, 0, nums.size() - 1);
    }

    TreeNode* createBST(vector<int>& nums, int l , int r) {
        // if (r < 0 || l >= nums.size() || l > r) return nullptr;
        if (l > r) return nullptr;
        int middle = (l + r) / 2;
        // cout << "l:" << l << " r:" << r << " middle:" << middle << endl;
        TreeNode* root = new TreeNode(nums[middle]);
        root->left = createBST(nums, l, middle - 1);
        root->right = createBST(nums, middle + 1, r);
        return root;
    }
};