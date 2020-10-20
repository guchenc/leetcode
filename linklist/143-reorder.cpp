#include "../alg.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 经观察，重新排列后的链表实际上是将原链表从中间拆开，再依次连接起来得到的结果
    // - 通过快慢指针找到连表中点
    // - 逆序后链表
    // - 由于两链表节点数相差1,依次合并即可
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        ListNode* cur = head, *n = cur, *temp = nullptr;
        while (n != nullptr && n->next != nullptr) {
            temp = cur;
            cur = cur->next;
            n = n->next->next;
        }
        temp->next = nullptr;
        n = nullptr;
        while (cur != nullptr) {
            temp = cur->next;
            cur->next = n;
            n = cur;
            cur = temp;
        }
        cur = head;
        while (cur != nullptr) {
            temp = cur->next;
            cur->next = n;
            if (temp == nullptr) break;
            n = n->next;
            cur->next->next = temp;
            cur = temp;
        }
    }

    // 因为链表不支持下标访问，所以我们无法随机访问链表中任意位置的元素。
    // 因此比较容易想到的一个方法是，我们利用线性表存储该链表，然后利用线性表可以下标访问的特点，直接按顺序访问指定元素，重建该链表即可。
    // time: O(n) space: O(n)
    void reorderList3(ListNode* head) {
        if (head == nullptr) return;
        vector<ListNode*> nodes;
        ListNode* cur = head, *prev;
        while (cur != nullptr) nodes.push_back(cur), cur = cur->next;
        int i = 0, j = nodes.size() - 1;
        while (i != j && j != i + 1) {
            prev = nodes[j - 1];
            nodes[j]->next = nodes[i]->next;
            prev->next = nullptr;
            nodes[i]->next = nodes[j];
            i = i + 1;
            j = j - 1;
        }
    }

    // 递归 每次将末尾节点移动到当前处理节点的后面 time: O(n^2) space: O(n)
    void reorderList2(ListNode* head) {
        process(head);
    }

    void process(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return;
        ListNode* prev = nullptr, *cur = head;
        while (cur->next != nullptr) {
            prev = cur;
            cur = cur->next;       
        }
        cur->next = head->next;
        head->next = cur;
        prev->next = nullptr;
        process(cur->next);
    }

    // 利用哈希表存储每个节点的父节点
    // time: O(n) space: O(n)
    void reorderList1(ListNode* head) {
        if (head == nullptr) return;
        unordered_map<ListNode*, ListNode*> prevs;
        ListNode* cur, *n;
        n = head;
        cur = head->next;
        while (cur != nullptr) {
            prevs[cur] = n;
            n = cur;
            cur = cur->next;
        }
        cur = head;
        while (cur != n && cur->next != n) {
            n->next = cur->next;
            cur->next = n;
            cur = n->next;
            n = prevs[n];
        }
        n->next = nullptr;
    }

    void print(ListNode* head) {
        while (head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};