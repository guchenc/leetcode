/*
 * @Description: 划分字母区间
 * @Author: guchen
 * @Date: 2020-10-22 15:52:32
 * @LastEditTime: 2020-10-22 15:53:03
 */
#include "../alg.h"
class Solution {
public:
    // 由于题目限定小写字母 故可用数组替换哈希表
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int lastpos[26] = {-1};
        for (int i = 0; i < S.size(); i++) lastpos[S[i] - 'a'] = i;
        int begin = 0;
        while (begin < S.size()) {
            int end = lastpos[S[begin] - 'a'];
            for (int i = begin + 1; i < end; i++)
                end = max(lastpos[S[i] - 'a'], end);
            res.emplace_back(end - begin + 1);
            begin = end + 1;
        }
        return res;
    }

    // 用哈希表记录每个字符最后出现的位置 time: O(n) space: O(n)
    vector<int> partitionLabels1(string S) {
        vector<int> res;
        unordered_map<char, int> m;
        for (int i = 0; i < S.size(); i++) m[S[i]] = i;
        int begin = 0;
        while (begin < S.size()) {
            int end = m[S[begin]];
            for (int i = begin + 1; i < end; i++)
                if (m[S[i]] > end) end = m[S[i]];
            res.push_back(end - begin + 1);
            begin = end + 1;
        }
        return res;
    }
};