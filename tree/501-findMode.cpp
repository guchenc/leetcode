#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 利用Morris中序遍历将空间复杂度降为O(1)
    // time: O(n) space: O(1)
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        TreeNode* cur = root, *pre = nullptr, *node;
        int base, curcnt, maxcnt = 0;
        while (cur != nullptr) {
            if (cur->left != nullptr) {
                node = cur->left;
                while (node->right != nullptr && node->right != cur)
                    node = node->right;
                if (node->right == nullptr) {
                    node->right = cur;
                    cur = cur->left;
                } else {
                    node->right = nullptr;
                    update(res, pre, base, cur->val, curcnt, maxcnt);
                    pre = cur;
                    cur = cur->right;
                }
            } else {
                update(res, pre, base, cur->val, curcnt, maxcnt);
                pre = cur;
                cur = cur->right;
            }
        }
        return res;
    }

    void update(vector<int>& res, TreeNode* prev, int& base, int& cur, int& curcnt, int& maxcnt) {
        if (prev == nullptr || cur != prev->val) {
            base = cur;
            curcnt = 1;
        } else {
            curcnt++;
        }
        if (curcnt > maxcnt) {
            res.clear();
            res.push_back(cur);
            maxcnt = curcnt;
        } else if (curcnt == maxcnt) {
            res.push_back(cur);
        }
    }

    // 利用BST的中序遍历序列是一个有序序列这个性质
    // time: O(n) space: O(n)
    vector<int> findMode2(TreeNode* root) {
        vector<int> res, seq;
        stack<TreeNode*> s;
        if (root == nullptr)
            return seq;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if (node == nullptr) {
                node = s.top();
                s.pop();
                seq.push_back(node->val);
            } else {
                if (node->right != nullptr)  s.push(node->right);
                s.push(node);
                s.push(nullptr);
                if (node->left != nullptr)  s.push(node->left);
            }
        }
        // for (auto n : seq)
        //     cout << n << " ";
        // cout << endl;

        // 处理中序遍历得到的有序序列
        int cur, curcnt, maxcnt = 0;
        for (int i = 0; i < seq.size(); i++) {
            if (i == 0 || seq[i] != seq[i - 1]) {
                cur = seq[i];
                curcnt = 1;
            } else {
                curcnt++;
            }
            if (curcnt > maxcnt) {
                res.clear();
                res.push_back(seq[i]);
                maxcnt = curcnt;
            } else if (curcnt == maxcnt) {
                res.push_back(seq[i]);
            }
        }
        return res;
    }

    // 借助哈希map time: O(n) space: O(n)
    vector<int> findMode1(TreeNode* root) {
        unordered_map<int, int> m;
        vector<int> res;
        int maxcnt = 0;
        dfs(root, m);
        for (auto it = m.begin(); it != m.end(); it++) {
            maxcnt = max(it->second, maxcnt);
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second == maxcnt)
                res.push_back(it->first);
        }
        return res;
    }

    void dfs(TreeNode* root, unordered_map<int, int>& m) {
        if (root == nullptr)
            return;
        auto it = m.find(root->val);
        if (it == m.end())
            m.insert(make_pair(root->val, 1));
        else
            it->second += 1;
        dfs(root->left, m);
        dfs(root->right, m);
    }
};