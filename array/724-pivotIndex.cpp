/*
 * @Description: 寻找数组的中心索引
 * @Author: guchen
 * @Date: 2020-10-11 19:02:54
 * @LastEditTime: 2020-10-11 19:04:35
 */
#include <vector>
using namespace std;

class Solution {
public:
    // time: O(n) space: O(1)
    // 根据题目意思，pivot可以位于0/size-1处，此时相当于左/右侧无元素
    int pivotIndex(vector<int>& nums) {
        int sum = 0, total = 0;
        for (auto& n : nums) sum += n;
        for (int i = 0; i < nums.size(); i++) {
            if (sum - nums[i] == total * 2) return i;
            total += nums[i];
        }
        return -1;
    }
};