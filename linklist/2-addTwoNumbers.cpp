/*
 * @Description: 两数相加
 * @Author: guchen
 * @Date: 2020-09-17 18:50:47
 * @LastEditTime: 2020-10-19 13:26:56
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // 可以用该算法计算非负大整数的加法运算
    // time: O(max(m,n)) space: O(max(m,n))
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* n1 = l1, *n2 = l2, *dummy = new ListNode(-1), *tail = dummy;
        int sum = 0;    // 记录上一位进位与当前运算位数的和
        while (n1 != nullptr || n2 != nullptr || sum) {
            if (n1) sum += n1->val, n1 = n1->next;
            if (n2) sum += n2->val, n2 = n2->next;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            sum /= 10;;
        }
        tail = dummy;
        dummy = dummy->next;
        delete(tail);   // 释放dummy的堆空间，避免内存泄漏
        return dummy;
    }
};