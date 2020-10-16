/*
 * @Description: 回文链表
 * @Author: guchen
 * @Date: 2020-10-16 13:39:08
 * @LastEditTime: 2020-10-16 13:42:24
 */
#include "../alg.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    // time: O(n) space: O(1)
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;
        ListNode* n1 = head, *n2 = head, *back = nullptr;
        while (n2->next != nullptr && n2->next->next != nullptr) {
            n1 = n1->next;
            n2 = n2->next->next;
        }
        if (n2->next == nullptr)
            n1->next = reverse(n1->next);
        else
            n1->next = reverse(n1->next);
        back = n1;
        n1 = head, n2 = back->next;
        while (n1 != nullptr && n2 != nullptr) {
            if (n1->val != n2->val) {
                back->next = reverse(back->next);
                return false;
            }
            n1 = n1->next;
            n2 = n2->next;
        }
        return true;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr, *cur = head, *next;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    // time: O(n) space: O(n)
    bool isPalindrome1(ListNode* head) {
        vector<int> seq;
        ListNode* cur = head;
        while (cur != nullptr) {
            seq.push_back(cur->val);
            cur = cur->next;
        }
        int l = 0, r = seq.size() - 1;
        while (l < r) {
            if (seq[l++] != seq[r--]) return false;
        }
        return true;
    }
};