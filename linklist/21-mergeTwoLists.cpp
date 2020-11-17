/*
 * @Description: 合并两个有序链表
 * @Author: guchen
 * @Date: 2020-09-18 22:41:20
 * @LastEditTime: 2020-11-17 19:26:08
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0), *tail = dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail = tail->next = l1;
                l1 = l1->next;
            } else {
                tail = tail->next = l2;
                l2 = l2->next;
            }
        }
        if (l1 == nullptr) tail = tail->next = l2;
        else  tail = tail->next = l1;
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }

    // 迭代
    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0), *tail = dummy;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                tail = tail->next = l2;
                break;
            } else if (l2 == nullptr) {
                tail = tail->next = l1;
                break;
            }
            if (l1->val < l2->val) {
                tail = tail->next = l1;
                l1 = l1->next;
            } else {
                tail = tail->next = l2;
                l2 = l2->next;
            }
        }
        return dummy->next;
    }

    // 递归，子问题：每次返回两个升序链表中较小的头节点
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode* min;
        if (l1->val < l2->val) {
            min = l1;
            l1 = l1->next;
        } else {
            min = l2;
            l2 = l2->next;
        }
        min->next = mergeTwoLists1(l1, l2);
        return min;
    }

};
class Solution {
public:
    // time: O(n + m) space: O(1)
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0), *tail = dummy;   // 锟斤拷锟斤拷dummy锟斤拷锟津化诧拷锟斤拷锟斤拷锟�
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail = tail->next = l1;
                l1 = l1->next;
            } else {
                tail = tail->next = l2;
                l2 = l2->next;
            }
        }
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;
        tail = dummy->next;
        delete(dummy);  // 锟酵凤拷dummy锟斤拷锟斤拷锟斤拷锟节达拷泄漏
        return tail;
    }
};