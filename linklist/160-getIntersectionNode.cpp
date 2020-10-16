/*
 * @Description: 相交链表
 * @Author: guchen
 * @Date: 2020-09-21 19:11:45
 * @LastEditTime: 2020-10-15 16:49:27
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
    // 双指针 time: O(n + m)  space: O(1)
    // 用两个指针分别从两个链表头部开始遍历, 当链A(B)指针到达链尾时，令其指向链B(A)首部，继续遍历直至两者相等或者双双为null
    // - 若两链表相交，两个指针一定会在移动相同步数(A链头长+B链头长+两链重合部分长度))相等
    // - 若两链表不相交，两个指针一定会在移动相同步数(A链长+B链长)后同时为null
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
    // 借助set time: O(n + m) space: O(n) / O(m)
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