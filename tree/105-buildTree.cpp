/*
 * @Description: 从前序与中序遍历序列构造二叉树
 * @Author: guchen
 * @Date: 2020-09-25 16:09:32
 * @LastEditTime: 2020-09-25 16:10:22
 */
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 递归 time: O(n) space: O(n)
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int plen = preorder.size();
        int ilen = inorder.size();
        if (plen == 0 && ilen == 0)   return nullptr;
        return recursiveBuildTree(0, plen - 1, 0, ilen - 1, preorder, inorder);
    }

    TreeNode* recursiveBuildTree(int pleft, int pright, int ileft, int iright, vector<int>& preorder, vector<int>& inorder) {
        int licnt = 0, ricnt = 0;
        int rootval = preorder[pleft];
        for (int i = ileft; i <= iright; i++) {
            if (inorder[i] == rootval) {
                ricnt = iright - ileft - licnt;
                break;
            }
            licnt++;
        }
        TreeNode* root = new TreeNode(rootval);
        if (licnt > 0) root->left = recursiveBuildTree(pleft + 1, pleft + licnt, ileft, ileft + licnt - 1, preorder, inorder);
        if (ricnt > 0) root->right = recursiveBuildTree(pleft + 1 + licnt, pright, ileft + licnt + 1, iright, preorder, inorder);
        return root;
    }
};