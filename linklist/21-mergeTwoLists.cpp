/*
 * @Description: �ϲ�������������
 * @Author: guchen
 * @Date: 2020-09-18 22:41:20
 * @LastEditTime: 2020-09-18 22:41:58
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
    // time: O(n + m) space: O(1)
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0), *tail = dummy;   // ����dummy���򻯲������
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
        delete(dummy);  // �ͷ�dummy�������ڴ�й©
        return tail;
    }
};