/*
 * @Description: ��������
 * @Author: guchen
 * @Date: 2020-09-20 19:04:19
 * @LastEditTime: 2020-09-20 19:05:07
 */
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // ����set��������������ÿһ���ڵ㣬�ȴ�set�в������Ƿ���ڣ���������˵�����ڻ�������true
    // time: O(n) space: O(n)
    bool hasCycle(ListNode *head) {
        set<ListNode*> s;
        ListNode* node = head;
        while (node != nullptr) {
            auto itr = s.find(node);
            if (itr != s.end())
                return true;
            s.insert(node);
            node = node->next;
        }
        return false;
    }

    // ���Ž�-����ָ��(���Ű�) time: O(n) space: O(1)
    // �������ڻ�����ָ����ȵ�������β��������false
    // �����ڻ�����ָ�����ս�׷����ָ�룬����true
    bool hasCycle2(ListNode *head) {
        ListNode* fast = head->next, *low = head;
        while (fast != low) {
            if (fast == nullptr || fast->next == nullptr)
                return false;
            fast = fast->next->next;
            low = low->next;
        }
        return true;
    }
    // ����ָ�� time: O(n)  space: O(1)
    bool hasCycle1(ListNode *head) {
        if (head == nullptr)
            return false;
        ListNode* fast = head->next, *low = head;
        while (fast != nullptr) {
            if (fast == low)    // �����ڻ�����ָ��ؽ�׷����ָ�룬��ʱ����true
                return true;
            if (fast->next == nullptr)
                return false;
            fast = fast->next->next;    // ��ָ��һ����2��
            low = low->next;    // ��ָ��һ����1��
        }
        return false;
    }
};