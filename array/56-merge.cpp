/*
 * @Description: 合并区间
 * @Author: guchen
 * @Date: 2020-10-11 20:14:17
 * @LastEditTime: 2020-10-11 20:14:42
 */
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
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