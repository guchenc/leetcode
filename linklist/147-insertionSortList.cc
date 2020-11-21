/*
 * @Description: 对链表进行插入排序
 * @Author: guchen
 * @Date: 2020-11-20 20:56:08
 * @LastEditTime: 2020-11-20 20:56:41
 */
#include "../alg.h"
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // find postion for every node and link it to dummy
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0), *target = head;  // next node to be placed
        while (target != nullptr) {
            ListNode* next = target->next;  // save next target first because target->next will be changed
            ListNode* cur = dummy;
            while (cur->next != nullptr && cur->next->val < target->val) cur = cur->next;   // find position for target
            target->next = cur->next;   // link target to ordered list
            cur->next = target;
            target = next;
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};