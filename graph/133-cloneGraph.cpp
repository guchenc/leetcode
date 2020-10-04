/*
 * @Description: 克隆图
 * @Author: guchen
 * @Date: 2020-10-04 19:40:44
 * @LastEditTime: 2020-10-04 19:49:24
 */
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    // 递归 time: O(n) space: O(n)
    unordered_map<int, Node*> nnodes;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        auto it = nnodes.find(node->val);
        if (it != nnodes.end()) return it->second;
        Node* nnode = new Node(node->val);
        nnodes[node->val] = nnode;
        for (auto neighbor : node->neighbors) {
            nnode->neighbors.push_back(cloneGraph(neighbor));
        }
        return nnode;
    }

    // 递归 time: O(n) space: O(n)
    Node* cloneGraph1(Node* node) {
        if (node == nullptr) return nullptr;
        unordered_map<int, Node*> nnodes;
        dfs(node, nnodes);
        return nnodes[1];
    }

    void dfs(Node* node, unordered_map<int, Node*>& nnodes) {
        Node* nnode = new Node(node->val);
        nnodes[node->val] = nnode;
        for (auto n : node->neighbors) {
            auto it = nnodes.find(n->val);
            if (it == nnodes.end()) {
                dfs(n, nnodes);
                nnode->neighbors.push_back(nnodes[n->val]);
            } else  
                nnode->neighbors.push_back(it->second);
        }
    }
};