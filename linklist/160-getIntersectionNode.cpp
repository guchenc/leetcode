/*
 * @Description: �ཻ����
 * @Author: guchen
 * @Date: 2020-09-21 19:11:45
 * @LastEditTime: 2020-09-21 19:12:56
 */
#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // ˫ָ�� time: O(n + m)  space: O(1)
    // ������ָ��ֱ����������ͷ����ʼ����, ����A(B)ָ�뵽����βʱ������ָ����B(A)�ײ�����������ֱ��������Ȼ���˫˫Ϊnull
    // - ���������ཻ������ָ��һ�������ƶ���ͬ����(A��ͷ��+B��ͷ��+�����غϲ��ֳ���))���
    // - ���������ཻ������ָ��һ�������ƶ���ͬ����(A����+B����)��ͬʱΪnull
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa = headA, *pb = headB;
        if (pa == nullptr || pb == nullptr)
            return nullptr;
        while (pa != pb) {
            pa = pa == nullptr ? headB : pa->next;
            pb = pb == nullptr ? headA : pb->next;
        }
        return pa;
    }
    // ����set time: O(n + m) space: O(n) / O(m)
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        ListNode* interp = nullptr;
        unordered_set<ListNode*> s;
        while (headA != nullptr) {
            s.insert(headA);
            headA = headA->next;
        }
        while (headB != nullptr) {
            if (s.count(headB) > 0) {
                interp = headB;
                break;
            }
            headB = headB->next;
        }
        return interp;
    }
};