/*
 * @Description: ���������������
 * @Author: guchen
 * @Date: 2020-09-12 15:59:08
 * @LastEditTime: 2020-09-21 15:33:49
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include "tree_utils.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Morris���� time: O(n) space: O(1)
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* node, *cur;
        vector<int> ans;
        cur = root;
        while (cur != nullptr) {
            if (cur->left != nullptr) {
                node = cur->left;
                // �ҵ���ǰ�ڵ�cur�������������ҽڵ㣬����ǰ�ڵ��������������е�ǰ�̽��
                while (node->right != nullptr && node->right != cur)
                    node = node->right;
                if (node->right == nullptr) {   // ʹ��ǰ�ڵ����ҽڵ����ָ��ָ��ǰ�ڵ�
                    node->right = cur;
                    cur = cur->left;
                } else {
                    node->right = nullptr;  // �ָ���ǰ�ڵ��һ����Ϊcurʱ���õ����ҽڵ�����ӽڵ�Ϊ��
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
            } else {
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ans;
    }
    // ���� time: O(n) space: O(n)
    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        if (root == nullptr)
            return res;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if (node != nullptr) {
                if (node->right != nullptr)
                    s.push(node->right);
                s.push(node);
                s.push(nullptr);
                if (node->left != nullptr)
                    s.push(node->left);
            } else {
                node = s.top();
                s.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
};

int main()
{
    string s;
    cin >> s;
    cout << "serialize string: " << s << endl;
    TreeNode* root = deserialize(s);
    Solution so;
    vector<int> res = so.inorderTraversal(root);
    for (auto val : res) {
        cout << val << " ";
    }
    return 0;
}