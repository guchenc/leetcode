/*
 * @Description: 奇偶链表
 * @Author: guchen
 * @Date: 2020-10-16 11:21:34
 * @LastEditTime: 2020-10-16 11:22:19
 */
#include "../alg.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* odd = head, *even = head->next, *evenHead = even;
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }

    ListNode* oddEvenList2(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* odd = head, *even = head->next, *evenhead = even;
        while (even->next != nullptr && even->next->next != nullptr) {
            odd = odd->next = even->next;
            even = even->next = even->next->next;
        }
        if (even->next != nullptr) {
            odd = odd->next = even->next;
            even->next = nullptr;
        }
        odd->next = evenhead;
        return head;
    }

    ListNode* oddEvenList1(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* oddtail = head, *eventail = head->next, *cur = head->next->next;
        int pos = 3;
        while (cur != nullptr) {
            if (pos % 2 != 0) {
                ListNode* next = cur->next;
                cur->next = oddtail->next;
                oddtail = oddtail->next = cur;
                eventail->next = next;
                cur = next;
            } else {
                eventail = cur;
                cur = cur->next;
            }
            pos++;
        }
        return head;
    }
};