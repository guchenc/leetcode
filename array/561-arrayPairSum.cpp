/*
 * @Description: 数组拆分I
 * @Author: guchen
 * @Date: 2020-10-13 09:29:50
 * @LastEditTime: 2020-10-13 09:30:17
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 要使得min(ai, bi)总和最大，每个配对之间的损失必须最小，即ai - bi最小(ai > bi)
    // 直接排序，将两两连续的数配对，其配对损失始终为1,故min(ai, bi)总和最大
    // time: O(n) space: O(1)
    int arrayPairSum(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2) 
            res += nums[i];
        return res;
    }
};