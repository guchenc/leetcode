/*
 * @Description: 最大间距
 * @Author: guchen
 * @Date: 2020-11-26 20:25:06
 * @LastEditTime: 2020-11-26 20:25:16
 */
#include "../alg.h"
class Solution {
public:
    // 利用桶排序 只关注桶间差值，不关注桶内顺序
    // 两个核心问题:
    // - 每个桶的长度，即每个桶中元素的范围： bucketlen = (max(nums) - min(nums)) / (len(nums) - 1)
    // - 分多少个桶： nbucket = (max(nums) - min(nums)) / bucketlen + 1
    // 每个数在哪个桶中：bucket_idx = (num - min(nums)) / bucketlen
    int maximumGap(vector<int>& nums) {
        int N = nums.size();
        if (N < 2) return 0;
        int maxNum = *max_element(nums.begin(), nums.end());
        int minNum = *min_element(nums.begin(), nums.end());
        int bucketlen = (maxNum - minNum - 1) / (N - 1) + 1; // 整数除法向上取整
        int nbucket = (maxNum - minNum) / bucketlen + 1;
        vector<int> bucket_cnt(nbucket, 0); // 计算每个桶中有多少元素
        vector<int> bucket_max(nbucket, INT_MIN), bucket_min(nbucket, INT_MAX); // 只要桶中有元素，桶内最大值最小值都会更新

        for (int i = 0; i < N; i++) {
            int idx = (nums[i] - minNum) / bucketlen;
            bucket_cnt[idx]++;
            bucket_max[idx] = max(bucket_max[idx], nums[i]);   
            bucket_min[idx] = min(bucket_min[idx], nums[i]);   
        }

        int maxdiff = 0;
        int lidx = -1;
        for (int i = 0; i < nbucket; i++) {
            if (bucket_cnt[i] == 0) continue;
            if (lidx == -1) {   // 确认相对位置为左边的桶
                lidx = i;
                continue;
            } 
            // 确定相对位置为右边的桶，计算间距
            maxdiff = max(bucket_min[i] - bucket_max[lidx], maxdiff);
            lidx = i;
        }
        return maxdiff;
    }
};