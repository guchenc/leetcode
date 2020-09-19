/*
 * @Description: 
 * @Author: guchen
 * @Date: 2020-09-19 17:50:43
 * @LastEditTime: 2020-09-19 22:43:33
 */
#include <deque>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 将链表成环，先遍历一次链表，计算出总长度len并设置双指针指向头尾节点
    // 因为右旋len次相当于没有旋转，因此实际只需要右旋转k%len次即可，大幅缩减冗余移动操作
    // 因为将头尾指针向后移动比向前移动简单(实际上起到左旋的效果), 因此利用左旋转len-k次实现右旋转k次
    // time: O(n) space: O(1)
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* ans = nullptr, *node, *tail;      
        int len = 0;
        if (head == nullptr)
            return head;
        node = head;
        while (node != nullptr) {
            tail = node;
            node = node->next;
            len++;
        }
        tail->next = head;
        ans = head;
        k %= len;
        k = len - k;
        while (k-- > 0) {
            ans = ans->next;
            tail = tail->next;
        }
        tail->next = nullptr;
        return ans;
    }

    // 使用双端队列，先将整个链表节点按顺序送入deque，之后根据k将队尾元素送入队首，最后再依次出队成链
    // time: O(n) space: O(n)
    ListNode* rotateRight2(ListNode* head, int k) {
        ListNode* node, *ans, *tail;
        deque<ListNode*> q;
        int len = 0;
        if (!head)
            return head;
        node = head;
        while (node != nullptr) {
            q.push_back(node);
            len++;
            node = node->next;
        }
        k %= len;
        while (k-- > 0) {
            q.push_front(q.back());
            q.pop_back();
        }
        // for (auto n : q)
        //     cout << n->val << endl;
        ans = nullptr;
        while (!q.empty()) {
            node = q.front();
            q.pop_front();
            if (ans == nullptr) {
                ans = node;
                tail = node;
                continue;
            }
            tail = tail->next = node;
        } 
        tail->next = nullptr; // 终止链表
        return ans;
    }

    // ListNode* rotateRight1(ListNode* head, int k) {
    //     if (!head || !head->next)
    //         return head;
    //     ListNode* node = head, *tailprev;
    //     while (!head->next->next)
    //         head = head->next;
    //     tailprev = head->next;
    //     while (k > 0) {
    //         tailprev->next->next = head;
    //         head = tailprev->next;
    //         k--;
    //     }
    //     return nullptr;
    // }
};