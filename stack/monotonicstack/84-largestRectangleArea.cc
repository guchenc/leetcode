/*
 * @Description: 柱状图中最大的矩形
 * @Author: guchen
 * @Date: 2020-12-29 21:14:18
 * @LastEditTime: 2020-12-29 21:14:41
 */
#include "../alg.h"
class Solution {
public:
    // 20-12-28
    // 单调栈 time: O(n) space: O(n)
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        if (heights.size() == 1) return heights[0];
        int ret = 0;
        heights.push_back(-1);
        stack<int> s;
        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int width = 0, height = heights[s.top()]; s.pop();
                if (s.empty()) width = i;
                else width = i - s.top() - 1;
                ret = max(ret, width * height);
            } 
            s.push(i);
        }
        return ret;
    }

    // 单调栈 time: O(n) space: O(n)
    int largestRectangleArea2(vector<int>& heights) {
        if (heights.empty()) return 0;
        if (heights.size() == 1) return heights[0];
        heights.push_back(-1);
        int N = heights.size(), maxArea = INT_MIN;
        stack<int> s; 
        s.push(0);
        for (int i = 1; i < N; i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int width = 0, height = heights[s.top()]; s.pop();
                if (s.empty()) width = i ;
                else width = i - s.top() - 1; 
                maxArea = max(maxArea, height * width);
            }
            s.push(i);
        }
        return maxArea;
    }

    // 超时 矩形面积取决于连续柱状图中最矮的那个 time: O(n^2) space: O(1)
    int largestRectangleArea1(vector<int>& heights) {
        int maxArea = INT_MIN;
        if (heights.empty()) return 0;
        int N = heights.size();
        for (int i = 0; i < N; i++) {
            int l , r;
            l = r = i;
            while (l - 1 >= 0 && heights[l - 1] >= heights[i]) l--;
            while (r + 1 < N && heights[r + 1] >= heights[i]) r++;
            maxArea = max(maxArea, (r - l + 1) * heights[i]);
        }
        return maxArea;
    }
};
