/*
 * @Description: 加油站
 * @Author: guchen
 * @Date: 2020-11-18 20:49:54
 * @LastEditTime: 2020-11-18 20:50:07
 */
#include "../alg.h"

class Solution {
public:
    // 一次遍历法 关键点: 若从x到不了y，则从[x, y)中任意一个点都到不了y
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int N = gas.size();
        int bucket = 0;
        int i = 0, cnt, next;
        while (i < N) {
            bucket = 0;
            cnt = 0;
            next = i;
            while (cnt < N) {   // 当前走了多少站
                bucket += gas[next] - cost[next];
                next = (next + 1) % N;
                if (bucket < 0) break;
                cnt++;
            }
            if (cnt == N) return i;
            i = i + cnt + 1;
        }
        return -1;
    }

    // 迭代 依然是尝试从每一个加油站出发
    int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
        int N = gas.size();
        int next, bucket = 0;
        for (int i = 0; i < N; i++) {
            bucket = 0;
            next = i;
            do {
                bucket += gas[next] - cost[next];
                next = (next + 1) % N;
                if (bucket < 0) break;
            } while (next != i);
            if (bucket >= 0) return i;
        }
        return -1;
    }

    // 暴力解法，尝试从每一个加油站出发，测试能不能走完一圈
    int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
        int N = gas.size();
        bool flag = false;
        for (int i = 0; i < N; i++) {
            flag = tryout(gas, cost, i, (i + 1) % N, gas[i] - cost[i]);
            if (flag) return i;           
        }
        return -1;
    }

    bool tryout(vector<int>& gas, vector<int>& cost, int start, int next, int bucket) {
        if (next == start && bucket >= 0) return true;
        if (bucket <= 0) return false;
        return tryout(gas, cost, start, (next + 1) % gas.size(), bucket - cost[next] + gas[next]); 
    }
};
