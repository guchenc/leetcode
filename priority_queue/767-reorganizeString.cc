/*
 * @Description: 重构字符串
 * @Author: guchen
 * @Date: 2020-11-30 16:28:08
 * @LastEditTime: 2020-11-30 16:28:32
 */
#include "../alg.h"
class Solution {
public:
    // 优先队列
    string reorganizeString(string S) {
        string res;
        int N = S.size();
        vector<int> count(26, 0);
        int maxcnt = 0;
        for (int i = 0; i < N; i++) {
            count[S[i] - 'a']++;
            maxcnt = max(maxcnt, count[S[i] - 'a']);
        }
        if (maxcnt > (N + 1) / 2) return "";
        auto cmp = [&](const char& letter1, const char& letter2) {
            return count[letter1 - 'a'] < count[letter2 - 'a'];
        };
        priority_queue<char, vector<char>, decltype(cmp)> pqueue(cmp);

        for (int i = 0; i < 26; i++)
            if (count[i] > 0) pqueue.push(i + 'a');

        while (pqueue.size() > 1) {
            char letter1 = pqueue.top(); pqueue.pop();
            char letter2 = pqueue.top(); pqueue.pop();
            res += letter1;
            res += letter2;
            int idx1 = letter1 - 'a';
            int idx2 = letter2 - 'a';
            count[idx1]--;
            count[idx2]--;
            if (count[idx1] > 0) pqueue.push(letter1);
            if (count[idx2] > 0) pqueue.push(letter2);
        }
        if (pqueue.size() > 0)
            res += pqueue.top();
        return res;
    }
};
