/*
 * @Description: 视频拼接
 * @Author: guchen
 * @Date: 2020-10-24 15:23:59
 * @LastEditTime: 2020-10-24 15:24:17
 */
#include "../alg.h"

class Solution {
public:
    // DP
    // dp[i]表示将区间[0, i]覆盖所需要的最小片段数量
    // dp[i] = min{dp[aj]} + 1 (aj <= i <= bj)
    // dp[0] = 0, dp[i] = INT_MAX;
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> dp(T + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 1; i <= T; i++) {
            for (auto& it : clips) {
                if (it[0] <= i && it[1] >= i)
                    dp[i] = min(dp[it[0]] + 1, dp[i]);  // 理解为何这么写
            }
            // for (int j = 0; j < T+1; j++) {
            //     cout << " dp[" << j << "]=";
            //     if (dp[j] > INT_MAX - 10) cout << "-";
            //     else cout << dp[j];
            // } 
            // cout << endl;
        }
        return dp[T] == INT_MAX - 1 ? -1 : dp[T];
    }

    int videoStitching1(vector<vector<int>>& clips, int T) {
        // sort(clips.begin(), clips.end(), compRightBound); // O(nlognn)
        // for (auto v : clips) {
        //     for (auto n : v) cout << n << " ";
        //     cout << endl;
        // }
        int cnt = 0, left = 0;
        vector<int> maxright(clips.size());
        for (int i = 0; i < clips.size(); i++) {
            
        }
        return 0;
    }
};