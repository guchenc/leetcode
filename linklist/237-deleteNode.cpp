/*
 * @Description: 删除链表节点
 * @Author: guchen
 * @Date: 2020-09-23 19:38:43
 * @LastEditTime: 2020-09-23 19:39:25
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 无法获得node的prev从而无法直接删除node，那么就令node的值为下一节点的值，从而将其作为下一节点的prev，删除下一节点
    // time: O(1) space: O(1)
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
    
    // 双指针 time: O(n) space: O(1)
    void deleteNode1(ListNode* node) {
        ListNode* n = node, *follow = node->next;
        while (follow->next != nullptr) {
            n->val = follow->val;
            n = follow;
            follow = follow->next;
        }
        n->val = follow->val;
        n->next = nullptr;
    }
};