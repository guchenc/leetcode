/*
 * @Description: 
 * @Author: guchen
 * @Date: 2020-09-12 17:34:49
 * @LastEditTime: 2020-09-12 19:21:45
 */
#include <iostream>
#include <vector>
#include "treedef.h"
#include <sstream>
#include <queue>

string serialilze(TreeNode* root)
{
    ostringstream out;
    queue<TreeNode*> q;
    if (root == nullptr)
        return "[]";
    out << "[";
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            out << node->val;
            q.push(node->left);
            q.push(node->right);
        } else {
            out << "null";
        }
        if (!q.empty())
            out << ",";
    }
    out << "]";
    return out.str();
}

TreeNode* deserialize(string data)
{
    if (data.size() < 3)
        return nullptr; 
    istringstream iss(data.substr(1, data.size() - 2));
    string s;
    vector<TreeNode*> nodes;
    while (getline(iss, s, ',')) {
        if (s == "null")
            nodes.push_back(nullptr);
        else
            nodes.push_back(new TreeNode(stoi(s)));
    }
    for (int i = 0, j = 1; i < nodes.size(); i++) {
        if (nodes[i]) {
            nodes[i]->left = nodes[j++];
            if (j < nodes.size())
                nodes[i]->right = nodes[j++];
        }
    }
    return nodes[0];
}

// int main()
// {
//     string s;
//     cin >> s;
//     cout << "serialize string: " << s << endl;
//     TreeNode* root = deserialize(s);
//     s = serialilze(root);
//     cout << "reserialize string: " << s << endl;
//     return 0;
// }