/*
 * @Description: 反转链表
 * @Author: guchen
 * @Date: 2020-09-17 17:24:39
 * @LastEditTime: 2020-11-14 17:36:08
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // 递归 优雅！ 核心思想是当前节点之后的所有节点已经逆序完毕，只需要将自身接到之后的已逆序链表即可
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* nhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return nhead;
    }

    // using recursion
    // time: O(n) space: O(1)
    ListNode* reverseList3(ListNode* head) {
        return reverse(nullptr, head);
    }
    ListNode* reverse(ListNode* prev ,ListNode* cur) {
        if (cur == nullptr)
            return prev;
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        return reverse(prev, cur);
    }

    // using iteration
    // time: O(n) space: O(1) 
    ListNode* reverseList(ListNode* head) {
        ListNode* node = head, *prev = nullptr, *next = nullptr;
        while (node != nullptr) {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }

    // using stack<int>
    // change value of each listnode instead of its strcuture
    // time: O(n) space: O(n)
    ListNode* reverseList2(ListNode* head) {
        stack<int> s;
        ListNode* node = head;
        while (node != nullptr) {
            s.push(node->val);
            node = node->next;
        }
        node = head;
        while (!s.empty()) {
            int n = s.top();
            s.pop();
            node->val = n;
            node = node->next;
        }
        return head;
    }

    // using stack<ListNode*>
    // time: O(n) space: O(n)
    ListNode* reverseList1(ListNode* head) {
        stack<ListNode*> s;
        ListNode* node = head, *nhead = nullptr, *tail = nullptr;
        while (node != nullptr) {
            s.push(node);
            node = node->next;
        }
        while (!s.empty()) {
            node = s.top();
            s.pop();
            if (nhead == nullptr) {
                nhead = node;
                tail = node;
                continue;
            }
            tail->next = node;
            tail = node;
        }
        tail->next = nullptr;
        // node = nhead;
        // while (node != nullptr) {
        //     cout << node->val << "-";
        //     node = node->next;
        // }
        return nhead;
    }
};