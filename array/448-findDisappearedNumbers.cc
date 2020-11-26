/*
 * @Description: 找到所有数组中消失的数字
 * @Author: guchen
 * @Date: 2020-11-26 21:08:03
 * @LastEditTime: 2020-11-26 21:08:21
 */
#include "../alg.h"
class Solution {
public:
    // 因为1 <= a[i] <= n，所以数组元素和下标可以建立对应关系
    // 遍历一边数组，将当前元素对应下标(a[i] - 1)位置存储的值置为负数; 遍历结束后仍然是正数的下标所对应的数不存在
    // time: 0(n) space: O(1)
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            // for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
            // cout << endl;
            int tmp = abs(nums[i]);
            nums[tmp - 1] = -abs(nums[tmp - 1]);
        }
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0) res.push_back(i + 1);
        return res;
    }
    vector<int> findDisappearedNumbers1(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < nums.size(); i++) 
            if (nums[i] != i + 1) res.push_back(i + 1);
        return res;
    }

    // time: O(n) space: O(n)
    vector<int> findDisappearedNumbers2(vector<int>& nums) {
        unordered_set<int> exist;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
            exist.insert(nums[i]);
        for (int i = 0; i < nums.size(); i++)
            if (exist.find(i + 1) == exist.end()) res.push_back(i + 1);
        return res;
    }
};
