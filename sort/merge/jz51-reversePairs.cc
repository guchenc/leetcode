/*
 * @Description: 数组中的逆序对
 * @Author: guchen
 * @Date: 2020-12-29 21:09:55
 * @LastEditTime: 2020-12-29 21:10:19
 */
#include "../alg.h"
class Solution {
public:
    // 归并排序 不使用全局变量 time: O(nlogn) space: O(n)
    // 关键: 逆序对的数量与逆序对中较大元素之间的相对位置无关，但是较大元素按顺序排列方便我们计算逆序对的数量
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());
        return merge_sort(nums, tmp, 0, nums.size() - 1);
    }

    int merge_sort(vector<int>& nums, vector<int>& tmp, int lo, int hi) {
        if (lo >= hi) return 0;
        int mid = lo + (hi - lo) / 2;
        int leftPairs = merge_sort(nums, tmp, lo, mid);
        int rightPairs = merge_sort(nums, tmp, mid + 1, hi);
        if (nums[mid] <= nums[mid + 1]) return leftPairs + rightPairs;
        int crossPair = merge(nums, tmp, lo, mid, hi);
        return leftPairs + rightPairs + crossPair;
    }

    int merge(vector<int>& nums, vector<int>& tmp, int lo, int mid, int hi) {
        for (int k = lo; k <= hi; k++) tmp[k] = nums[k];
        int i = lo, j = mid + 1, crossPair = 0;
        for (int k = lo; k <= hi; k++) {
            if (i > mid) nums[k] = tmp[j++];
            else if (j > hi) nums[k] = tmp[i++];
            else if (tmp[i] <= tmp[j]) nums[k] = tmp[i++];
            else {
                crossPair += mid - i + 1;
                nums[k] = tmp[j++];
            }
        }
        return crossPair;
    }

    // 归并排序 time: O(nlogn) space: O(n)
    // 关键: 逆序对的数量与逆序对中较大元素之间的相对位置无关，但是较大元素按顺序排列方便我们计算逆序对的数量
    vector<int> tmp;
    int ret = 0;
    int reversePairs2(vector<int>& nums) {
        tmp.resize(nums.size());
        merge_sort2(nums, 0, nums.size() - 1); 
        return ret;
    }

    void merge_sort2(vector<int>& nums, int lo, int hi) {
        if (lo >= hi) return;   // 子数组只有一个元素，已经有序
        int mid = lo + (hi - lo) / 2;
        merge_sort2(nums, lo, mid);
        merge_sort2(nums, mid + 1, hi);
        if (nums[mid] <= nums[mid + 1]) return;
        merge2(nums, lo, mid, hi);
    }

    void merge2(vector<int>& nums, int lo, int mid, int hi) {
        for (int i = lo; i <= hi; i++) tmp[i] = nums[i];
        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; k++) {
            if (i > mid) nums[k] = tmp[j++];
            else if (j > hi) nums[k] = tmp[i++];
            else if (tmp[i] <= tmp[j]) nums[k] = tmp[i++];
            else {
                ret += mid - i + 1; // 归并排序的基础上添加该行即可
                nums[k] = tmp[j++];
            } 
        }
    }


    // 暴力解法 超时 time: O(n^2) space: O(1)
    int reversePairs1(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] > nums[j]) cnt++;
            }
        }
        return cnt;
    }

};