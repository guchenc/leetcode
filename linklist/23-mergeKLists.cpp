/*
 * @Description: 合并K个升序链表
 * @Author: guchen
 * @Date: 2020-09-18 23:26:24
 * @LastEditTime: 2020-09-18 23:27:33
 */
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0), *tail = dummy;
        if (lists.empty())
            return nullptr;
        int min;
        int over = 0;
        while (!over) {
            min = -1;
            over = 1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i]) {
                    if (min == -1)
                        min = i;
                    over = 0;
                    if (lists[i]->val < lists[min]->val)
                        min = i;
                }
            }
            if (over)
                break;
            tail->next = lists[min];
            lists[min] = lists[min]->next;
            tail = tail->next;
        }
        tail = dummy->next;
        delete(dummy);
        return tail;
    }
};