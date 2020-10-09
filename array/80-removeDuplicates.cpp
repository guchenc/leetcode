/*
 * @Description: 删除排序数组中的重复项II
 * @Author: guchen
 * @Date: 2020-10-09 16:58:26
 * @LastEditTime: 2020-10-09 16:59:00
 */
#include<vector>
using namespace std;

class Solution {
public:
    // 最优解 可适用于最多n次 双指针 不使用计数器 time: O(n) space: O(1)
    int removeDuplicates(vector<int>& nums) {
        int pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (pos < 2 || nums[i] != nums[pos - 2])
                nums[pos++] = nums[i];
        }
        return pos;
    }

    // 双指针 time: O(n) space: O(1)
    int removeDuplicates1(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int pos = 0, cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[pos]) {
                if (cnt != 2) {
                    pos++;
                    nums[pos] = nums[i];
                    cnt++;
                }
            } else {
                pos++;
                if (pos != i) nums[pos] = nums[i];  // 数组赋值语句其实也就是一条汇编指令，这样写有优化么?
                cnt = 1;
            }
        }
        return pos + 1;      
    }
};