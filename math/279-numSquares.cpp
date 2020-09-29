/*
 * @Description: 完全平方数
 * @Author: guchen
 * @Date: 2020-09-29 13:02:40
 * @LastEditTime: 2020-09-29 13:03:23
 */
#include <unordered_set>
#include <queue>
#include <math.h>
using namespace std;

class Solution {
public:

    // 双向BFS
    int numSquares(int n) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        unordered_set<int> visited;
        int cnt = 0;
        s1.insert(0);
        s2.insert(n);
        while (!s1.empty() && !s2.empty()) {
            auto& s = s1.size() > s2.size() ? s2 : s1;
            auto& b = s1.size() > s2.size() ? s1 : s2;
            int flag = 0;
            if (s == s1) flag = 1;  // +
            else flag = 0; // -

            unordered_set<int> temp;

            for (auto it = s.begin(); it != s.end(); it++) {
                int total = *it;
                if (b.find(total) != b.end()) return cnt;
                visited.insert(total);

                int sum;
                if (flag) {
                    int base = 1;
                    while ((sum = pow(base, 2) + total) <= n) {
                        if (visited.find(sum) == visited.end()) temp.insert(sum);
                        base++;
                    }
                } else {
                    int base = sqrt(total);
                    while ((sum = -pow(base, 2) + total) >= 0) {
                        if (visited.find(sum) == visited.end()) temp.insert(sum);
                        base--;
                    }
                }
            }
            s = temp;
            cnt++;
        }
        return -1;
    }

    //BFS
    int numSquares1(int n) {
        queue<int> q;
        unordered_set<int> s;
        int cnt = 0;
        q.push(0);
        s.insert(0);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int total = q.front(); q.pop();
                if (total == n) return cnt;
                int base = 1, sum;
                while ((sum = pow(base, 2) + total) <= n) {
                    if (s.find(sum) == s.end()) {
                        q.push(sum);
                        s.insert(sum);
                    }
                    base++;
                }
            }
            cnt++;
        }
        return -1;
    }
};