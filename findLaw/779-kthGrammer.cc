/*
 * @Description: 第K个语法符号
 * @Author: guchen
 * @Date: 2020-11-17 19:23:31
 * @LastEditTime: 2020-11-17 19:23:52
 */
#include "../alg.h"
class Solution {
public:
    // 将各层看成二叉树 
    //序号 记住满二叉树中父子节点序号的表达式关系
    //              1
    //          /        \   
    //      1                2
    //    /   \            /    \
    //  1       2        3       4
    // / \     /  \     /  \    / \ 
    //1   2   3    4   5    6  7   8
    
    //01排列
    //              0
    //          /        \   
    //      0                1
    //    /   \            /    \
    //  0       1        1       0
    // / \     /  \     /  \    / \ 
    //0   1   1    0   1    0  0   1
    int kthGrammar(int N, int K) {
        if (N == 1 && K == 1) return 0;
        int a = kthGrammar(N - 1, (K + 1) / 2);
        int b = -(a - 1);   // a = 0 -> b = 1 || a = 1 -> b = 0
        return K % 2 == 1 ? a : b;  // K为奇数则其值与父节点相同
    }

    // 队列 完全应该想到会超时，因为2^(N-1)
    int kthGrammar1(int N, int K) {
        queue<int> q;
        q.push(0);
        int cnt = 1;
        while (cnt <= N) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int n = q.front(); q.pop();
                if (n == 0) {
                    q.push(0);
                    q.push(1);
                } else {
                    q.push(1);
                    q.push(0);
                }
            }
            cnt++;
        }
        cnt = 1;
        while (cnt++ != K) q.pop();
        return q.front();
    }
};