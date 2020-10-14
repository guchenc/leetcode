/*
 * @Description: 移除元素
 * @Author: guchen
 * @Date: 2020-10-09 14:36:53
 * @LastEditTime: 2020-10-13 09:37:06
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // 双指针 每次遇到目标值，将该位置赋值为数组末尾的值，之后通过数组长度减一的方式逻辑抹去该值，但是会改变数组元素的顺序
    // time: O(n) space:(1)
    int removeElement(vector<int>& nums, int val) {
        int i = 0, len = nums.size();
        while (i < len) {
            // print_nums(nums, i);
            if (nums[i] == val) {
                nums[i] = nums[len - 1];
                len--;
            } else {
                i++;
            }
        }
        return len;
    }

    // 双指针 time: O(n) space: O(1)
    // [1,2,3,4,5] val = 1 会产生不必要的赋值 结果为[2,3,4,5,5]
    // 思考: 对于特殊情况的输入，考虑算法执行效果，思考优化方案
    int removeElement1(vector<int>& nums, int val) {
        int pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[pos] = nums[i];
                pos++;
            }
        }
        return pos;
    }

    void print_nums(vector<int>& nums, int round) {
        cout << "[" << round << "]: ";
        for (auto n : nums)
            cout << n << " ";
        cout << endl;
    }
};