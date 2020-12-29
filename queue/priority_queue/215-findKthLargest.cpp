/*
 * @Description: 数组的第K个最大元素
 * @Author: guchen
 * @Date: 2020-12-29 21:07:28
 * @LastEditTime: 2020-12-29 21:07:49
 */
#include "../alg.h"
class Solution {
public:
    // 优先队列 使用小根堆
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++) pq.push(nums[i]);
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }

    // 先排序
    int findKthLargest1(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};