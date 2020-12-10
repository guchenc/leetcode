/*
 * @Description: 将数组拆分成斐波那契序列
 * @Author: guchen
 * @Date: 2020-12-10 20:32:42
 * @LastEditTime: 2020-12-10 20:33:16
 */
#include "../alg.h"
class Solution {
public:
    // DFS + 回溯 + 剪枝 time: O() space: O()
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res;
        bool flag = dfs(res, S, 0);
        return flag ? res : vector<int>();
    }

    bool dfs(vector<int>& res, string& S, int idx) {
        if (idx == S.size() && res.size() >= 3) return true;    // 找到一个正确的切分方法
        long prevSum = 0;   // 使用long存储int，于INT_MAX相比判断是否溢出
        if (res.size() >= 2) {  // 当已经切分的数字大于等于2个时，判断前两个数组和是否溢出
            prevSum = (long)res[res.size() - 1] + res[res.size() - 2];  // 注意强制类型转换
            if (prevSum > INT_MAX) return false;    // 结果溢出，直接返回false
        } 
        for (int i = idx; i < S.size(); i++) {  // 递归尝试切分
            if (S[idx] == '0' && i > idx) return false; // 要切分的数字开始以0开头，后面的尝试结果直接丢弃，返回false
            long num = stol(S.substr(idx, i - idx + 1));    // 先转换为long避免溢出
            // printRes(res);
            // cout << "trying: " << num << endl;
            if (num > INT_MAX) return false;    // 若尝试的结果开始溢出，丢弃后面的尝试，返回false
            if (res.size() >= 2 && num != prevSum) continue;    // 若该次尝试不构成斐波那契数列，尝试下一个
            res.push_back(num);
            if (dfs(res, S, i + 1)) return true;    // 该次尝试构成斐波那契数列，从切分点后面开始继续切分
            res.pop_back();
        }
        return false;
    }

    void printRes(vector<int>& res) {
        cout << "res: [";
        for (auto c : res) cout << c << ",";
        cout << "] ";
    }
};
