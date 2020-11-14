/*
 * @Description: 两两交换链表中的节点
 * @Author: guchen
 * @Date: 2020-10-13 09:17:19
 * @LastEditTime: 2020-11-14 17:41:49
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 递归 time: O(n) space: O(n)
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* p = head->next;
        head->next = swapPairs(p->next);    // 注意这种处理方式
        p->next = head;
        return p;
    }

   // 迭代 time: O(n) space: O(1)
    ListNode* swapPairs1(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy, *cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            ListNode* tmp = cur;
            prev->next = cur->next;
            cur->next = cur->next->next;
            prev->next->next = tmp;
            prev = cur;
            cur = prev->next;
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res; 
    }

    // 迭代 time: O(n) space: O(1)
    ListNode* swapPairs2(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode(0, head), *prev = dummy, *p = head->next;    // 借助dummy简化特殊情况
        while (p != nullptr) {
            prev->next->next = p->next;
            p->next = prev->next;
            prev->next = p;
            prev = p->next;
            if (prev->next != nullptr && prev->next->next != nullptr) {
                p = prev->next->next;
            } else
                p = nullptr;
        }
        head = dummy->next;
        delete(dummy);
        return head;
    }

    // 迭代 time: O(n) space: O(1)
    ListNode* swapPairs1(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* prev = nullptr, *p = head->next;
        while (p != nullptr) {
            if (prev == nullptr)  {
                head->next = p->next;
                p->next = head;
                head = p;
                prev = head->next;
            } else {
                prev->next->next = p->next;
                p->next = prev->next;
                prev->next = p;
                prev = prev->next->next;
            }

            if (prev->next != nullptr && prev->next->next != nullptr)
                p = prev->next->next;
            else
                p = nullptr;
        }
        return head;
    }
};