/*
 * @Description: 二叉树的中序遍历
 * @Author: guchen
 * @Date: 2020-09-12 15:59:08
 * @LastEditTime: 2020-09-17 18:57:01
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include "tree_utils.h"

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if (root == NULL)
            return res;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node == nullptr) {
                node = st.top();
                st.pop();
                res.push_back(node->val);
            } else {
                if (node->right != nullptr)
                    st.push(node->right);
                st.push(node);
                st.push(nullptr);
                if (node->left != nullptr)
                    st.push(node->left);
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