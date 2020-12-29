/*
 * @Description: 排序链表
 * @Author: guchen
 * @Date: 2020-11-21 21:08:18
 * @LastEditTime: 2020-12-29 21:09:09
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
    // 归并排序 [head, tail)
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return nullptr;
        return merge_sort(head, nullptr);
    }

    ListNode* merge_sort(ListNode* head, ListNode* tail) {
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        // 将一个链表中间对半分
        ListNode* slow = head, *fast = head;
        while (fast != tail) {  // 注意这里取下界的方式！
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) fast = fast->next;
        }
        ListNode* p1 = merge_sort(head, slow);
        ListNode* p2 = merge_sort(slow, tail);
        return merge(p1, p2); 
    }

    // 合并两个有序链表
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(0), *tail = dummy;
        ListNode* p1 = head1, *p2 = head2;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val <= p2->val) {
                tail = tail->next = p1;
                p1 = p1->next;
            } else {
                tail = tail->next = p2;
                p2 = p2->next;
            }
        }
        tail->next = p1 == nullptr ? p2 : p1;
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};