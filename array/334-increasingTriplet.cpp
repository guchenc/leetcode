/*
 * @Description: 递增的三元子序列
 * @Author: guchen
 * @Date: 2020-10-28 20:46:40
 * @LastEditTime: 2020-10-28 20:46:49
 */
#include "../alg.h"

class Solution {
public:
    // 遍历一遍数组
    // min记录当前序列中最小元素
    // sec记录当前序列中的第二小元素 
    // 如果碰到一个数>min 且 >sec 说明找到三元组
    bool increasingTriplet(vector<int>& nums) {
        int min = INT_MAX, sec = INT_MAX;
        for (auto& n : nums) {
            if (n <= min) min = n;
            else if (n <= sec) {
                sec = n;
            } else {
                // cout << min << " " << sec << " " << n << endl;
                return true;
            } 
        }
        return false;
    }
};