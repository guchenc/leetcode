/*
 * @Description: 每日温度
 * @Author: guchen
 * @Date: 2020-09-29 21:44:17
 * @LastEditTime: 2020-09-29 21:45:11
 */
#include <vector>
#include <stack>
using namespace std;

class Solution {
public: 

    // 单调栈 time: O(n) space: O(n)
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        vector<int> res;
        res.resize(T.size());
        for (int i = 0; i < T.size(); i++) {
            while (!s.empty() && T[i] > T[s.top()]) {
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
    
    // 暴力解法 time: O(n^2) space: O(1)
    vector<int> dailyTemperatures1(vector<int>& T) {
        vector<int> v;
        int n = 0;
        bool flag = false;
        for (int i = 0; i < T.size(); i++) {
            for (int j = i + 1; j < T.size(); j++) {
                n++;
                if (T[j] > T[i]) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                v.push_back(n);
            else
                v.push_back(0);
            n = 0;
            flag = false;
        }
        return v;
    }
};