/*
 * @Description: 填充每个节点的下一个右侧节点指针
 * @Author: guchen
 * @Date: 2020-09-25 17:48:01
 * @LastEditTime: 2020-09-25 17:48:55
 */
#include <queue>
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:

    // 迭代 time: O(n) space: O(1)
    // - 要连接的节点有两种，同父兄弟节点和异父堂兄弟节点
    // - 任一层连接顺序一定是: 兄弟 - n * (堂兄弟-兄弟)
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        Node* begin = root->left, *parent = root;   // begin指向没一层的起始节点，parent指向上一层的起始节点
        while (begin != nullptr) {
            Node* node = begin;
            while (node != nullptr) {
                node->next = parent->right; // 连接兄弟节点
                // cout << node->val << "->" << parent->right->val << endl;;
                node = node->next;
                if (parent->next != nullptr) {
                    node->next = parent->next->left;
                    // cout << node->val << "->" << parent->next->left->val << endl;;
                    parent = parent->next;
                }
                node = node->next;
            }
            parent = begin; 
            begin = begin->left;// 连接下一层
        }
        return root;
    }

    // 递归 利用第N层的next连接第N+1层的next time: O(n) space: O(1)
    Node* connect2(Node* root) {
        if (root == nullptr) return nullptr;
        if (root->left != nullptr)
            root->left->next = root->right; // 连接兄弟节点
        if (root->right != nullptr && root->next != nullptr)
            root->right->next = root->next->left; // 连接相邻堂兄弟节点
        connect(root->left);
        connect(root->right);
        return root; 
    }

    

    // 层序遍历，一次处理一层 time: O(n) space: O(n)
    Node* connect1(Node* root) {
        queue<Node*> q;
        int layersz;
        if (root == nullptr) return nullptr;
        q.push(root);
        while (!q.empty()) {
            layersz = q.size();
            for (int i = 0; i < layersz; i++) {
                Node* node = q.front(); q.pop();
                if (i == layersz - 1)
                    node->next = nullptr;
                else
                    node->next = q.front();
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
        }
        return root;
    }
};