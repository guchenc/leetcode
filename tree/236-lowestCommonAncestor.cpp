/*
 * @Description: 二叉树的最近公共祖先
 * @Author: guchen
 * @Date: 2020-09-25 21:10:06
 * @LastEditTime: 2020-09-25 22:49:55
 */
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    // 遍历一遍树，将各节点作为键，各节点的唯一父节点作为值，插入哈希map
    // 从p开始向根节点进发，将路径上所有父节点(包括p自身)插入哈希表
    // 从q开始向跟节点进发，依次在p父节点构成的哈希表中查找路径上的节点，若找到则为最近公共祖先
    // time: O(n) space: O(n)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> father_map;
        unordered_set<TreeNode*> p_farthers;
        if (root == nullptr) return nullptr;
        father_map[root] = nullptr;
        dfs_fillmap(root, father_map);
        while (p != nullptr) {
            p_farthers.insert(p);
            p = father_map[p];
        }
        while (q != nullptr) {
            if (p_farthers.find(q) != p_farthers.end())
                return q;
            q = father_map[q];
        }
        return  nullptr;
    }

    void dfs_fillmap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& father_map) {
        if (root == nullptr) return;
        if (root->left != nullptr)
            father_map[root->left] = root;
        if (root->right != nullptr)
            father_map[root->right] = root;
        dfs_fillmap(root->left, father_map);
        dfs_fillmap(root->right, father_map);
    }

    // 递归 time: O(n) space: O(n)
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* comAncestor = nullptr;
        dfs(root, p, q, comAncestor);
        return comAncestor;
    }

    // 返回值表示以root为根的树中是否包含p或者q (即递归的子问题!!!)
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& comAncestor) {
        if (root == nullptr) return false;
        bool left = dfs(root->left, p, q, comAncestor);
        bool right = dfs(root->right, p, q, comAncestor);
        if ((left && right) || ((root == p || root == q) && (left || right)))
            comAncestor = root;
        return left || right || root == p || root == q;
    }
};