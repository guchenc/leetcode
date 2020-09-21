/*
 * @Description: 
 * @Author: guchen
 * @Date: 2020-09-21 15:49:48
 * @LastEditTime: 2020-09-21 15:51:09
 */
#include <vector>
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
    // Morris����(�����) time: O(n) space: O(1)
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* cur, *node;
        int sum = 0;
        cur = root;
        while (cur != nullptr) {
            if (cur->right != nullptr) { // �ҵ���ǰ�ڵ������������ҽڵ㣬����ǰ�ڵ�������������ǰ�̽ڵ�
                node = cur->right;
                while (node->left != nullptr && node->left != cur)// ���ҽڵ���ҽڵ����Ϊ�ջ���ָ��ǰ�ڵ�
                    node = node->left;
                if (node->left == nullptr) {
                    node->left = cur;
                    cur = cur->right;
                } else {
                    node->left = nullptr;   // �ָ����ҽڵ����ָ��
                    sum += cur->val;
                    cur->val = sum;
                    cur = cur->left;
                }
            } else {
                sum += cur->val;
                cur->val = sum;
                cur = cur->left;
            }
        }   
        return root;
    }

    // ���� ���õ���ʵ��BST�������������������������������ջs2��֮�����γ�ջ��ͳ���ѳ�ջ�ڵ�ֵ�ܺͣ����¸����ڵ�
    // time: O(n) space: O(n)
    TreeNode* convertBST2(TreeNode* root) {
        stack<TreeNode*> s, s2;
        TreeNode* node;
        if (root == nullptr)
            return nullptr;
        s.push(root);
        while (!s.empty()) {
            node = s.top();
            s.pop();
            if (node == nullptr) {
                node = s.top();
                s.pop();
                s2.push(node);
            } else {
                if (node->right != nullptr)
                    s.push(node->right);
                s.push(node);
                s.push(nullptr);
                if (node->left != nullptr)
                    s.push(node->left);
            }
        }
        int sum = 0;
        while (!s2.empty()) {
            node = s2.top();
            s2.pop();
            sum += node->val;
            node->val = sum;
        }
        return root;
    }

    // DFS �ݹ�ʵ�ַ��������
    TreeNode* convertBST1(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return root;
    }

    void dfs(TreeNode* root, int& sum) {
        if (root == nullptr)
            return;
        dfs(root->right, sum);
        sum += root->val;
        root->val = sum;
        dfs(root->left, sum);
    }
};