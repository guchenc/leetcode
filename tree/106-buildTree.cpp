/*
 * @Description: 从中序与后序遍历序列构造二叉树
 * @Author: guchen
 * @Date: 2020-09-25 15:55:13
 * @LastEditTime: 2020-09-25 16:11:19
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 不使用迭代器，直接使用下标
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ilen = inorder.size();
        int plen = postorder.size();
        if (ilen == 0 && plen == 0)
            return nullptr;
        return recursiveBuildTree(0, ilen - 1, 0, plen - 1, inorder, postorder);
    }

    TreeNode* recursiveBuildTree(int ileft, int iright, int pleft, int pright, vector<int>& inorder, vector<int>& postorder) {
        int rootval, licnt = 0, ricnt = 0;
        rootval = postorder[pright];
        for (int i = ileft; i <= iright; i++, licnt++) {
            if (inorder[i] == rootval) {
                ricnt = iright - ileft - licnt;
                break;
            }
        }
        TreeNode* root = new TreeNode(rootval);
        if (licnt != 0)
            root->left = recursiveBuildTree(ileft, ileft + licnt - 1, pleft, pleft + licnt - 1, inorder, postorder);
        if (ricnt != 0)
            root->right = recursiveBuildTree(ileft + licnt + 1, iright, pleft + licnt, pright - 1, inorder, postorder);
        return root;
    }

    // 递归，根据每个子树的中序和后续序列构造该子树，结合图示容易理解
    // time: O(n) space: O(n)
    TreeNode* buildTree1(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 && postorder.size() == 0)
            return nullptr;
        return recursiveBuildTree1(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }

    TreeNode* recursiveBuildTree1(vector<int>::iterator ibegin, vector<int>::iterator iend, vector<int>::iterator pbegin, vector<int>::iterator pend) {
        int ilen = iend - ibegin, plen = pend - pbegin;
        int rootval, licnt, ricnt;
        rootval = *(pend - 1);  // 一定成功，只有当子树节点不为0时才会进入递归
        licnt = 0;
        for (auto it = ibegin; it != iend; it++, licnt++) { // 根据中序遍历序列找到左子树节点数，从而知道右子树节点数
            if (*it == rootval) {
                ricnt = ilen - licnt - 1;
                break;
            }
        }
        TreeNode* root = new TreeNode(rootval);
        // cout << root->val << " " << licnt << " " << ricnt << endl;
        if (licnt != 0)
            root->left = recursiveBuildTree1(ibegin, ibegin + licnt, pbegin, pbegin + licnt);
        if (ricnt != 0)
            root->right = recursiveBuildTree1(ibegin + licnt + 1, iend, pbegin + licnt, pend - 1);
        return root;
    }

};