/*
 * @Description: 删除链表倒数第N个节点
 * @Author: guchen
 * @Date: 2020-10-15 17:25:54
 * @LastEditTime: 2020-10-15 17:29:57
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
    // 两次遍历法，将删除链表倒数第n个节点转化为删除链表正向第L-n+1个节点
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);    // 设置链表头节点简化删除链表头节点等操作
        ListNode* p = dummy->next;
        int L = 0;
        while (p != nullptr) {
            p = p->next;
            L++;
        }
        p = dummy;  // 注意从dummy开始遍历
        for (int i = 0; i < L - n; i++)
            p = p->next;
        p->next = p->next->next;
        return dummy->next;
    }

    // 快慢指针, 两者相距n + 1，slow指向要删除节点的前一个节点，fast指向要删除节点的后n个节点
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head), *slow = dummy, *fast = dummy;
        while (n >= 0) {
            fast = fast->next;
            n--;
        }
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }

};