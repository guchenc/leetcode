/*
 * @Description: 复制带随机指针的链表
 * @Author: guchen
 * @Date: 2020-10-20 12:04:05
 * @LastEditTime: 2020-10-20 12:04:53
 */
#include "../alg.h"

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    // 与解法一基本一致，利用哈西表存储原链表中每个节点的下标，避免重复遍历链表查找索引值 time: O(n) space: O(n)
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        vector<Node*> nodes;
        unordered_map<Node*, int> pos;
        Node* cur = head;
        int i = 0, index;
        while (cur != nullptr) {
            nodes.push_back(new Node(cur->val));
            pos[cur] = i;
            cur = cur->next;
            i++;
        }
        cur = head;
        i = 0;
        while (cur != nullptr) {
            if (cur->next != nullptr) nodes[i]->next = nodes[i+1];  // 串联拷贝节点
            if (cur->random != nullptr) nodes[i]->random = nodes[pos[cur->random]];
            cur = cur->next;
            i++;
        }
        return nodes[0];
    }

    int getindex(Node* head, Node* n) {
        int i = 0;
        while (head != nullptr) {
            if (head == n) return i;
            head = head->next;
            i++;
        }
        return -1;
    }
};