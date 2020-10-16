/*
 * @Description: 移除链表元素
 * @Author: guchen
 * @Date: 2020-10-16 10:27:36
 * @LastEditTime: 2020-10-16 10:28:54
 */
#include "../alg.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0), *cur;
        dummy->next = head;
        cur = dummy;
        while (cur->next != nullptr) {
            if (cur->next->val == val)
                cur->next = cur->next->next;
            else cur = cur->next;
        }
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};