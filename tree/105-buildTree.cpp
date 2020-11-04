/*
 * @Description: 从前序与中序遍历序列构造二叉树
 * @Author: guchen
 * @Date: 2020-09-25 16:09:32
 * @LastEditTime: 2020-11-03 20:33:38
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildChildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* buildChildTree(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if (pl > pr) return nullptr;
        int rootval = preorder[pl];
        int mid = 0, leftcnt = 0;
        for (int i = il; i <= ir; i++) {
            if (inorder[i] == rootval) {
                mid = i;
                break;
            }
            leftcnt++;
        }
        TreeNode* root = new TreeNode(rootval);
        root->left = buildChildTree(preorder, inorder, pl + 1, pl + leftcnt, il, il + leftcnt);
        root->right = buildChildTree(preorder, inorder, pl + leftcnt + 1, pr, mid + 1, ir); 
        return root;      
    }

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