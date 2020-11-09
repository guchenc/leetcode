/*
 * @Description: 最接近原点的K个点
 * @Author: guchen
 * @Date: 2020-11-09 17:31:50
 * @LastEditTime: 2020-11-09 17:32:03
 */
#include "../alg.h"
class Solution {
public:
    // 根据欧几里德距离排序 time: O(nlogn) space: O(1)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [](vector<int>& x, vector<int>& y) {
            return pow(x[0], 2) + pow(x[1], 2) < pow(y[0], 2) + pow(y[1], 2);
        });
        vector<vector<int>> res(points.begin(), points.begin() + K);
        return res;
    }

    // 暴力解法 
    vector<vector<int>> kClosest1(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        multimap<double, vector<pair<int, int>>> dism;
        int cnt = 0;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0], y = points[i][1];
            double dis = sqrt(pow(x, 2) + pow(y, 2));
            auto it = dism.find(dis);
            if (it == dism.end()) dism.insert({dis, {{x, y}}});
            else it->second.push_back({x, y});
        }
        for (auto& it : dism) {
            // cout << it.first << ":";
            // for (auto& p : it.second)
            //     cout << "[" << p.first << "," << p.second << "] ";
            // cout << endl;
            for (auto& p : it.second) {
                res.push_back({p.first, p.second});
                if (++cnt == K) break;
            }
            if (cnt == K) break;
        }
        return res;
    }
};