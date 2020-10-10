/*
 * @Description: 环形链表
 * @Author: guchen
 * @Date: 2020-09-20 19:04:19
 * @LastEditTime: 2020-10-10 15:57:13
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
    // 利用set，遍历链表，对于每一个节点，先从set中查找其是否存在，若存在则说明存在环，返回true
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

    // 最优解-快慢指针(优雅版) time: O(n) space: O(1)
    // 若不存在环，快指针必先到达链表尾部，返回false
    // 若存在环，快指针最终将追上慢指针，返回true
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
    // 快慢指针 time: O(n)  space: O(1)
    bool hasCycle1(ListNode *head) {
        if (head == nullptr)
            return false;
        ListNode* fast = head->next, *low = head;
        while (fast != nullptr) {
            if (fast == low)    // 若存在环，快指针必将追到慢指针，此时返回true
                return true;
            if (fast->next == nullptr)
                return false;
            fast = fast->next->next;    // 快指针一次走2步
            low = low->next;    // 慢指针一次走1步
        }
        return false;
    }
};