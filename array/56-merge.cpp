/*
 * @Description: 合并区间
 * @Author: guchen
 * @Date: 2020-10-11 20:14:17
 * @LastEditTime: 2020-10-24 15:25:40
 */
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.size() < 1) return res;
        int l, r;
        sort(intervals.begin(), intervals.end());
        l = intervals[0][0], r = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > r) {
                res.push_back({l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            } else {
                r = max(r, intervals[i][1]);
            }
        }
        res.push_back({l, r});
        return res;
    }
    // time: O() space: O(n)
    // - 按照左区间大小将区间进行排序
    // - 遍历区间，将当前区间插入结果集
    // - 遍历后面的所有区间，若区间可以和当前区间合并且还未被合并到其他区间，通过修改res[idx]的
    vector<vector<int>> merge1(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int idx = 0, N = intervals.size();
        vector<bool> picked(N, false);
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < N; i++) {
            if (picked[i]) continue;
            res.push_back(intervals[i]);
            picked[i] = true;
            for (int j = i + 1; j < N; j++) {
                if (intervals[j][0] <= res[idx][1]) {
                    res[idx][1] = max(res[idx][1], intervals[j][1]);
                    picked[j] = true;
                }
            }
            idx++;
        }
        return res;
    }
    // 排序 + 双指针 time: O(n^2) space: O(1)
    // 排序后的区间存在三种情况:
    //      -  ---- ++++
    //      -  ----***++
    //      -  ---***---
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.size() < 1) return res;
        // select_sort(intervals);
        sort(intervals.begin(), intervals.end());
        // for (auto& n : intervals) {
        //     cout << "[" << n[0] << "," << n[1] << "], ";
        // }
        // cout << endl;
        int l = intervals[0][0], r = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > r) {
                res.push_back({l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            } else if (intervals[i][1] > r) {
                r = intervals[i][1];
            }
        }
        res.push_back({l, r});  // 注意需要将最后一个区间单独加入结果列表
        return res;
    }

    void select_sort(vector<vector<int>>& intervals) {
        for (int i = 0; i < intervals.size(); i++) {
            int minleft = i;
            for (int j = i; j < intervals.size(); j++) 
                if (intervals[j][0] < intervals[minleft][0]) minleft = j;
            // swap(intervals[i], intervals[minleft]);
            swap(intervals[i][0], intervals[minleft][0]);
            swap(intervals[i][1], intervals[minleft][1]);
        }
    }
};