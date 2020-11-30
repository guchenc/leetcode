/*
 * @Description: 合并两个有序数组
 * @Author: guchen
 * @Date: 2020-10-09 18:36:49
 * @LastEditTime: 2020-11-30 16:55:40
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m + n - 1;
        int i = m - 1, j = n - 1;
        while (idx >= 0 && i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) nums1[idx--] = nums1[i--];
            else nums1[idx--] = nums2[j--];
        }
        while (i >= 0) nums1[idx--] = nums1[i--];
        while (j >= 0) nums1[idx--] = nums2[j--];
    }
};

class Solution {
public:
    // merge2为了避免数据覆盖需要创建nums1的副本，为了使空间复杂度降至O(1)，从后往前赋值
    // time: O(n + m) space: O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = n + m - 1, i1 = m - 1, i2 = n - 1;
        while (i1 >= 0 && i2 >= 0) {
            if (nums1[i1] >= nums2[i2]) nums1[pos] = nums1[i1--];
            else nums1[pos] = nums2[i2--];
            pos--;
        }
        // i1 >=0 i2 == -1 直接结束
        while (i2 >= 0) nums1[pos--] = nums2[i2--];
    }

    // 创建nums1的副本，然后遍历nums1和nums2，每次取最小值赋值到相应位置 time: O(n + m) space: O(m)
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums(nums1);
        int i = 0, i1 = 0, i2 = 0;
        while (i1 < m && i2 < n) {
            if (nums[i1] > nums2[i2]) nums1[i] = nums2[i2++];
            else nums1[i] = nums[i1++];
            i++;
        }
        while (i1 < m) nums1[i++] = nums[i1++];
        while (i2 < n) nums1[i++] = nums2[i2++];
    }

    // 暴力解法 先拼接 再排序 time: O((n+m)log(n+m)) ? space: O(1)
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++) nums1[m++] = nums2[i];
        sort(nums1.begin(), nums1.end());
    }
};