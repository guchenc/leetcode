/*
 * @Description: 盛最多水的容器
 * @Author: guchen
 * @Date: 2020-09-21 16:29:22
 * @LastEditTime: 2020-11-27 22:45:03
 */
#include "../alg.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int res = INT_MIN;
        while (l < r) {
            res = max(min(height[l], height[r]) * (r - l), res);
            if (height[l] >= height[r]) r--;
            else l++;
        }
        return res;
    }
    // 双指针 time: O(n) space: O(1)
    int maxArea(vector<int>& height) {
        int len = height.size();
        if (len < 2)
            return 0;
        int max = 0, l = 0, r = len - 1;
        while (l < r) {
            int hi = height[r] > height[l] ? height[l] : height[r];
            int area = hi * (r - l);
            max = area > max ? area : max;
            // 由于左右指针向中间移动，区域宽变小了
            // 若想使面积变大，必须使原本短的(造成瓶颈)边变大，因此选择移动短边
            if (height[l] <= height[r]) 
                l++;
            else
                r--;
        }
        return max;

    }
    // 暴力解法 time: O(n^2) space: O(1)
    int maxArea1(vector<int>& height) {
        int len = height.size();
        if (len < 2)
            return 0;
        int max = 0;
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                int hi = height[i] >= height[j] ? height[j] : height[i];
                int area = hi * (j - i);
                if (area > max)
                    max = area;
            }
        }
        return max;
    }
};