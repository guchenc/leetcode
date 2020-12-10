/*
 * @Description: 二叉搜索树与双向链表
 * @Author: guchen
 * @Date: 2020-12-10 20:21:23
 * @LastEditTime: 2020-12-10 20:22:06
 */
#include "../alg.h"
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    // 基于递归中序遍历
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return nullptr;
        Node* head = nullptr, *prev = nullptr;
        dfs(root, head, prev);
        head->left = prev;
        prev->right = head;
        return head;
    }
    
    void dfs(Node* root, Node*& head, Node*& prev) {
        if (root == nullptr) return;
        dfs(root->left, head, prev);
        if (head == nullptr) head = root;
        root->left = prev;
        if (prev != nullptr) prev->right = root;
        prev = root;
        dfs(root->right, head, prev);
    }


    // 类似Morris中序遍历
    Node* treeToDoublyList1(Node* root) {
        if (root == nullptr) return nullptr;
        Node* head = nullptr, *prev = nullptr;
        Node* cur = root;
        while (cur != nullptr) {
            if (cur->left != nullptr) {
                Node* succ = cur->left;
                while (succ->right != nullptr && succ->right != cur) succ = succ->right;
                if (succ->right == nullptr) {
                    succ->right = cur;
                    cur = cur->left;
                } else {
                    cur->left = succ;
                    prev = cur;
                    cur = cur->right;
                }
            } else {
                if (head == nullptr) head = cur;    // 第一个碰到的左子树为空的结点为head结点
                cur->left = prev;   // 将其左子树指向链表前一个结点
                if (prev != nullptr) prev->right = cur; // 将前一个结点的右子树指向当前节点，这里需要判空是因为头结点无前一个结点
                prev = cur;
                cur = cur->right;
            }
        }
        // 连接头尾结点
        prev->right = head;
        head->left = prev;
        return head;
    }
};