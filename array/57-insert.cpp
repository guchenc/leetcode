/*
 * @Description: 插入区间
 * @Author: guchen
 * @Date: 2020-11-04 19:32:48
 * @LastEditTime: 2020-11-04 19:32:58
 */
#include "../alg.h"
class Solution {
public:
    // 模拟法，time: O(n) space: O(1)
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int begin = newInterval[0], end = newInterval[1];
        bool placed = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (begin > intervals[i][1]) {  // 新区间在当前区间右侧且没有交集
                res.push_back(intervals[i]);
            } else if (end < intervals[i][0]) { // 新区间在当前区间左侧且没有交集，且在第一次碰到这种区间时将新区间加入结果集
                if (!placed) {
                    res.push_back({begin, end});
                    placed = true;
                }
                res.push_back(intervals[i]);
            } else {    // 新区间和当前区间有交集，将并集作为新区间
                begin = min(intervals[i][0], begin);
                end = max(intervals[i][1], end);
            }
        }
        if (!placed) res.push_back({begin, end});
        return res;
    }
};