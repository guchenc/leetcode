/*
 * @Description: 寻找两个正序数组的中位数
 * @Author: guchen
 * @Date: 2020-11-30 16:53:21
 * @LastEditTime: 2020-11-30 16:53:40
 */
#include "../alg.h"
class Solution {
public:
    // 先合并两个有序数组，再按照中位数定义获得结果
    // time: O(m + n) space: O(m + n)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int M = nums1.size(), N = nums2.size();
        vector<int> tmp(M + N);
        merge(tmp, nums1, nums2);
        return (tmp[(M + N + 1) / 2  - 1] + tmp[(M + N + 2) / 2 - 1]) / 2.0;
    }

    void merge(vector<int>& tmp, vector<int>& nums1, vector<int>& nums2) {
        int idx = nums1.size() + nums2.size() - 1;
        int i = nums1.size() - 1, j = nums2.size() - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) tmp[idx--] = nums1[i--];
            else tmp[idx--] = nums2[j--];
        }
        while (i >= 0) tmp[idx--] = nums1[i--];
        while (j >= 0) tmp[idx--] = nums2[j--];
    }
};
