/*
 * @Description: 扁平化多级双向链表
 * @Author: guchen
 * @Date: 2020-10-19 13:24:10
 * @LastEditTime: 2020-10-19 13:25:24
 */
#include "../alg.h"

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public: 
    // 将多级双向链表看作是二叉树，由先序遍历结果构成的链表即为结果
    // 貌似没办法在DFS过程中修改原有节点，只能构造新的节点，思路不错，但是不适合本题
    // time: O(n) space: O(n)
    vector<Node*> nodes;
    Node* flatten(Node* head) {
        if (head == nullptr) return nullptr;
        dfs(head);
        Node* dummy = new Node;
        Node* tail, *prev = dummy;
        for (auto n : nodes) {
            prev->next = n;
            n->prev = prev;
            n->child = nullptr;
            prev = n;
            tail = n;
        }
        head = dummy->next;
        delete dummy;
        head->prev = nullptr;
        tail->next = nullptr;
        return head;
    }

    void dfs(Node* n) {
        if (n == nullptr) return;
        nodes.push_back(n);
        dfs(n->child);
        dfs(n->next);
    }

    // 递归 time: O(n) space: O(h) h表示链表层数  
    // 学习递归函数原型的设计!
    Node* flatten2(Node* head) {
        if (head == nullptr) return nullptr;
        process(head, nullptr, nullptr);
        return head;
    }

    void process(Node* chead, Node* prev, Node* follow) {
        if (chead == nullptr) return;
        Node* cur = chead, *tail;
        while (cur != nullptr) {
            process(cur->child, cur, cur->next);
            cur->child = nullptr;
            tail = cur;
            cur = cur->next;
        } 
        if (prev != nullptr) {
            prev->next = chead;
            chead->prev = prev;
        }
        if (follow != nullptr) {
            tail->next = follow;
            follow->prev = tail;
        }
    }

    // 迭代法 主链会被遍历一次，每个子链会被遍历2次，time:O(n+2*L) space:O(1) n为第一层链表长度，L为除第一层之外所有子层长度和
    // - 每次遍历一个节点，若当前节点的child不为空，，将其子链插入到主链
    // - 重复上述操作
    Node* flatten1(Node* head) {
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->child != nullptr) {
                Node* chead = cur->child, *n = chead;
                while (n->next != nullptr) n = n->next;
                n->next = cur->next;
                if (cur->next != nullptr)
                    cur->next->prev = n;
                chead->prev = cur;
                cur->next = chead;
            }
            cur->child = nullptr;
            cur = cur->next;
        }
        return head;
    }
};