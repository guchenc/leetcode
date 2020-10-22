/*
 * @Description: 回文链表
 * @Author: guchen
 * @Date: 2020-10-16 13:39:08
 * @LastEditTime: 2020-10-22 15:53:50
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
        ListNode* p = head, *q = head, *middle;
        while (q != nullptr && q->next != nullptr) {    // 找到中间节点(n/2+1)
            p = p->next;
            q = q->next->next;
        }
        middle = p;
        // 将以middle开始的后半段反转，利用temp记录反转后的起始节点，注意反转后，middle前一个节点的next仍然指向middle
        ListNode* temp = reverse(middle);
        p = head;
        q = temp;
        while (p != middle) {   // 同时遍历middle左半段链表和反转后的右链表，直到左半段遍历完全(以middle为界限)
            if (p->val != q->val) {
                // 注意借助temp恢复右链表，由于middle前一个节点的next没变过，所以恢复右链表后，左右链表自动成。自动成链
                reverse(temp);  
                return false;
            }
            p = p->next;
            q = q->next;
        }
        reverse(temp);
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