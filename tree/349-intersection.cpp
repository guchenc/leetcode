/*
 * @Description: 两个数组的交集
 * @Author: guchen
 * @Date: 2020-11-03 20:35:45
 * @LastEditTime: 2020-11-03 20:35:56
 */
#include "../alg.h"
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> set;
        sort(nums2.begin(), nums2.end());
        for (auto& n : nums1) set.insert(n);
        for (int i = 0; i < nums2.size(); i++) {
            if (set.find(nums2[i]) != set.end()) {
                res.push_back(nums2[i]);
                while (i + 1 < nums2.size() && nums2[i + 1] == nums2[i]) i++;
            } 
        } 
        return res;
    }
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int idx1 = 0, idx2 = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (idx1 < nums1.size() && idx2 < nums2.size()) {
            if (nums1[idx1] < nums2[idx2]) idx1++;
            else if (nums1[idx1] > nums2[idx2]) idx2++;
            else {
                res.push_back(nums1[idx1]);
                while (idx1 + 1 < nums1.size() && nums1[idx1 + 1] == nums1[idx1]) idx1++;
                idx1++;
                while (idx2 + 1 < nums2.size() && nums2[idx2 + 1] == nums2[idx2]) idx2++;
                idx2++;
            }
        }
        return res;
    }
};