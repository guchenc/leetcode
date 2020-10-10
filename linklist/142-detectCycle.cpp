/*
 * @Description: 环形链表II
 * @Author: guchen
 * @Date: 2020-09-20 19:45:52
 * @LastEditTime: 2020-10-10 16:12:18
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
    // 快慢指针 time: O(n) space: O(1)
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode* fast = head, *low = head;
        int flag = 1;   // 最开始fast = low，使循环条件成立
        while (flag || fast != low) {
            flag= 0;
            if (fast == nullptr || fast->next == nullptr)    // 无环
                return nullptr;
            fast = fast->next->next;
            low = low->next;
        }
        // 有环，据分析当快慢指针相遇时，慢指针再走a步(a为链表首节点到环入口的距离)即到达环入口，遂令dummy从链表首部和low一同移动，当low = dummy时，即表明low走了a步，此时low和dummy都指向环入口
        ListNode* dummy = head;
        while (dummy != low) {
            // cout << dummy->val << " " << low->val << endl;
            dummy = dummy->next;
            low = low->next;
        }
        return dummy;
    }
};