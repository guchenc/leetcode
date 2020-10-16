/*
 * @Description: 填充每个节点的下一个右侧节点指针II
 * @Author: guchen
 * @Date: 2020-09-25 19:31:42
 * @LastEditTime: 2020-10-15 15:24:57
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
    // 优雅版迭代 同下
    Node* connect(Node* root) {
        Node* dummy = new Node(0), *cur, *tail;
        dummy->next = root;
        while (dummy->next != nullptr) {
            cur = dummy->next;
            dummy->next = nullptr;
            tail = dummy;
            while (cur != nullptr) {
                if (cur->left != nullptr) tail = tail->next = cur->left;
                if (cur->right != nullptr) tail = tail->next = cur->right;
                cur = cur->next;
            }
        }
        return root;
    }
    
    // 迭代(最优解)，处理当前层时，用dummy将下一层节点连接起来，当前层结束后，借助构造的下一层链表处理下一层
    // time: O(n) space: O(1)
    Node* connect(Node* root) {
        Node* dummy = new Node; // 用于连接各层堂兄弟节点
        Node* cur = root;   // 指向当前要处理的层节点
        while (cur != nullptr) {
            Node* tail = dummy; // 指向各层链表的尾结点
            while (cur != nullptr) {    // 遍历由dummy连接起来的层节点链表
                if (cur->left != nullptr)
                    tail = tail->next = cur->left;
                if (cur->right != nullptr)
                    tail = tail->next = cur->right;
                cur = cur->next;
            }
            cur = dummy->next;  // 将cur指向下一层起始节点
            dummy->next = nullptr;  // 置空dummy
            // if (tail == dummy) break; 和上面的步骤效果相同
        }
        return root;
    }

    // 递归 time: O(n) space: O(1) 不计入递归栈空间
    Node* connect2(Node* root) {
        if (root == nullptr) return nullptr;
        if (root->left != nullptr) {
            if (root->right != nullptr) root->left->next = root->right;
            else root->left->next = findnext(root->next);
        }
        if (root->right != nullptr)
            root->right->next = findnext(root->next);
        connect(root->right); // 必须先连根节点右子树的堂兄弟节点，若先连根节点左子树，会导致findnext返回不正确的值
        connect(root->left);
        return root;
    }

    Node* findnext(Node* root) {    // 寻找堂兄弟节点
        if (root == nullptr) return nullptr;
        if (root->left != nullptr) return root->left;
        if (root->right != nullptr) return root->right;
        return findnext(root->next);
    }

    // 层序遍历 time: O(n) space: O(n)
    Node* connect1(Node* root) {
        int layersz = 0;
        queue<Node*> q;
        if (root == nullptr) return nullptr;
        q.push(root);
        while (!q.empty()) {
            layersz = q.size();
            for (int i = 0; i < layersz; i++) {
                Node* node = q.front(); q.pop();
                if (i != layersz - 1)
                    node->next = q.front();
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
        }
        return root;
    }
};