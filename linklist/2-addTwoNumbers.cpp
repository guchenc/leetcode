/*
 * @Description: �������
 * @Author: guchen
 * @Date: 2020-09-17 18:50:47
 * @LastEditTime: 2020-09-17 23:11:19
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // �����ø��㷨����Ǹ��������ļӷ�����
    // time: O(max(m,n)) space: O(max(m,n))
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* n1 = l1, *n2 = l2, *dummy = new ListNode(-1), *tail = dummy;
        int sum = 0;    // ��¼��һλ��λ�뵱ǰ����λ���ĺ�
        while (n1 != nullptr || n2 != nullptr || sum) {
            if (n1) sum += n1->val, n1 = n1->next;
            if (n2) sum += n2->val, n2 = n2->next;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            sum /= 10;;
        }
        tail = dummy;
        dummy = dummy->next;
        delete(tail);   // �ͷ�dummy�Ķѿռ䣬�����ڴ�й©
        return dummy;
    }
};