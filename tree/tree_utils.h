/*
 * @Description: 
 * @Author: guchen
 * @Date: 2020-09-12 17:36:46
 * @LastEditTime: 2020-09-12 17:41:15
 */
#include <string>
using namespace std;

struct  TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


string serialilze(TreeNode* root);
TreeNode* deserialize(string data);