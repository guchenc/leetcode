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
    // ������ɻ����ȱ���һ������������ܳ���len������˫ָ��ָ��ͷβ�ڵ�
    // ��Ϊ����len���൱��û����ת�����ʵ��ֻ��Ҫ����תk%len�μ��ɣ�������������ƶ�����
    // ��Ϊ��ͷβָ������ƶ�����ǰ�ƶ���(ʵ������������Ч��), �����������תlen-k��ʵ������תk��
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

    // ʹ��˫�˶��У��Ƚ���������ڵ㰴˳������deque��֮�����k����βԪ��������ף���������γ��ӳ���
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
        tail->next = nullptr; // ��ֹ����
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