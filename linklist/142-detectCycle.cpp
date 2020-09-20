/*
 * @Description: ��������II
 * @Author: guchen
 * @Date: 2020-09-20 19:45:52
 * @LastEditTime: 2020-09-20 19:46:32
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // ����ָ�� time: O(n) space: O(1)
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode* fast = head, *low = head;
        int flag = 1;   // �ʼfast = low��ʹѭ����������
        while (flag || fast != low) {
            flag= 0;
            if (fast == nullptr || fast->next == nullptr)    // �޻�
                return nullptr;
            fast = fast->next->next;
            low = low->next;
        }
        // �л����ݷ���������ָ������ʱ����ָ������a��(aΪ�����׽ڵ㵽����ڵľ���)�����ﻷ��ڣ�����dummy�������ײ���lowһͬ�ƶ�����low = dummyʱ��������low����a������ʱlow��dummy��ָ�����
        ListNode* dummy = head;
        while (dummy != low) {
            // cout << dummy->val << " " << low->val << endl;
            dummy = dummy->next;
            low = low->next;
        }
        return dummy;
    }
};