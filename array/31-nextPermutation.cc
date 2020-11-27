/*
 * @Description: 下一个排列
 * @Author: guchen
 * @Date: 2020-11-27 22:39:15
 * @LastEditTime: 2020-11-27 22:39:37
 */
#include "../alg.h"
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) return;
        int i = N - 1;
        while (i >= 1 && nums[i] <= nums[i - 1]) i--;
        if (i > 0) {
            for (int j = N - 1; j >= i; j--) {
                if (nums[j] > nums[i - 1]) {
                    swap(nums[j], nums[i - 1]);
                    break;
                } 
            }
        }
        reverse(nums.begin() + i, nums.end());  
        // 交换后的[i..N-1]序列必然非严格降序，逆序一下就行，不用排序，如何证明？
        // i-1 < i >= i+1 >= .. >= j-1 >= j >= j+1 >= ... >= N-1
        // 根据算法遍历规则：
        // nums[j+1] <= nums[i-1] 必然成立，否则不会轮到j
        // nums[j-1] >= nums[j] 必然成立，否则不会轮到i
        // nums[j] > nums[i-1]必然成立
        // 故nums[j-1] >= nums[j] > nums[i-1] >= nums[j+1]
        // 即nums[j-1] > nums[i-1] >= nums[j+1]
        // 只需执行O(n)的逆序即可使得[i...N-1]这个递减序列递增，使得逆序对交换后的序列增幅最小
    }

    // 为了寻找下一个更大的排列，需要寻找一个逆序对(a,b)，使得a尽可能靠右且b尽可能小，同时使得逆序对交换后，整个排列增幅最小
    void nextPermutation2(vector<int>& nums) {
        if (nums.empty()) return; 
        for (int i = nums.size() - 1; i >= 1; i--) {
            if (nums[i - 1] >= nums[i]) continue;
            // i-1 < i >= i+1 >= ...>= nums.size() - 1
            for (int j = nums.size() - 1; j >= i; j--) {// 从i-1右侧开始找，找到第一个大于nums[i-1]的元素与之交换
                if (nums[j] > nums[i - 1]) {
                    swap(nums[j], nums[i - 1]);
                    sort(nums.begin() + i, nums.end()); // 使得增幅最小
                    return;
                }
            }
        }
        reverse(nums.begin(), nums.end());
    }

    void nextPermutation1(vector<int>& nums) {
        if (nums.empty()) return; 
        int i;
        for (i = nums.size() - 1; i >= 1; i--) {
            if (nums[i] > nums[i - 1]) break;
        }
        if (i == 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        int idx = i;
        for (int j = i; j < nums.size(); j++)
            if (nums[j] < nums[idx] && nums[j] > nums[i - 1]) idx = j;
        swap(nums[i - 1], nums[idx]);
        sort(nums.begin() + i, nums.end());
    }
};