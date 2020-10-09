/*
 * @Description: 长度最小的子数组
 * @Author: guchen
 * @Date: 2020-10-08 21:36:47
 * @LastEditTime: 2020-10-08 21:37:29
 */
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    // 滑动窗口 (直接使用下标) time: O(n) space: O(1)
    int minSubArrayLen(int s, vector<int>& nums) {
        int ws = 0, we = 0, sum = 0;
        int minlen = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= s) {
                if (minlen == 0) minlen = we - ws + 1;
                else minlen = min(minlen, we - ws + 1);
                sum -= nums[ws];
                ws++;
            }
            we++;
        }
        return minlen;
    }

    // 滑动窗口 (使用queue维护)time: O(n) space: O(n)
    int minSubArrayLen1(int s, vector<int>& nums) {
        int minlen = INT32_MAX, sum = 0;
        // int start = 0, minstart = 0;
        queue<int> q;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            q.push(nums[i]);
            // print_window(q);
            while (sum >= s) {
                if (q.size() < minlen) {
                    minlen = q.size();
                    // minstart = start;
                } 
                int front = q.front();
                q.pop();
                // start++;
                sum = sum - front;
                // print_window(q);
            }
        }
        // print_res(nums, minstart, minlen);
        return minlen == INT32_MAX ? 0 : minlen;
    }
    void print_res(vector<int>& nums, int start, int minlen) {
        if (minlen == INT32_MAX)
            return;
        for (int i = start; i < start + minlen; i++) {
            cout << nums[i] << " ";
        }
    }
    void print_window(queue<int> q) {
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
};