/*
 * @Description: 任务调度器
 * @Author: guchen
 * @Date: 2020-11-30 16:26:35
 * @LastEditTime: 2020-11-30 16:27:26
 */
#include "../alg.h"
class Solution {
public:
    // 手动排序，这种方法没办法获得任务执行序列，因为在排序的过程中，计数下标和任务名已经不是一一对应的了
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (int i = 0; i < tasks.size(); i++)
            count[tasks[i] - 'A']++;
        sort(count.begin(), count.end());

        int left = tasks.size();
        int ncycle = 0;
        while (left > 0) {
            for (int i = 25; i >= 25 - n; i--) {
                if (i >= 0 && count[i] > 0) {
                    count[i]--;
                    left--;
                }
                ncycle++;
                if (left == 0) break;
            }
            sort(count.begin(), count.end());
        }
        return ncycle;
    }

    // 使用优先队列，按照剩余任务数大小维护任务
    int leastInterval1(vector<char>& tasks, int n) {
        int N = tasks.size();
        vector<int> count(26, 0);
        for (int i = 0; i < N; i++)
            count[tasks[i] - 'A']++;

        auto cmp = [&](const char& task1, const char& task2) {
            return count[task1 - 'A'] < count[task2 - 'A'];
        };
        priority_queue<char, vector<char>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < 26; i++)
            if (count[i] > 0) pq.push(i + 'A');
        int cycle = 0;
        while (!pq.empty()) {
            queue<char> round;
            for (int i = 0; i < n + 1; i++) {
                if (pq.empty()) {
                    // cout << "sleep->";
                } else {
                    char task = pq.top(); pq.pop();
                    // cout << task << "->";
                    count[task - 'A']--;
                    if (count[task - 'A'] > 0) 
                        round.push(task);
                }
                cycle++;
                if (pq.empty() && round.empty()) break; // 当处理完所有任务后，提前结束，避免多于的cycle
            }
            while (!round.empty()) {
                char c = round.front(); round.pop();
                pq.push(c);
            }
        }
        return cycle;
    }
};