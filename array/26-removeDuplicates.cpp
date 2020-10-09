/*
 * @Description: 删除排序数组中的重复项
 * @Author: guchen
 * @Date: 2020-10-09 16:31:08
 * @LastEditTime: 2020-10-09 16:31:37
 */
#include <vector>
using namespace std;

class Solution {
public:
    // time: O(n) space: O(1)
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        int pos = 0;    // pos指向当前得到的最后一个不重复元素的位置
        for (int i = 1; i < size; i++) {
            if (nums[i] != nums[pos]) {
                pos++;
                if (i == pos) continue; // 避免不必要的赋值 例如[1,2,3,4]
                nums[pos] = nums[i];
            }
        }
        return pos + 1;
    }

    // time: O(n) space: O(1)
    int removeDuplicates1(vector<int>& nums) {
        int pos = 0;    // pos指向下一个要存放单独元素的位置
        for (int i = 0; i < nums.size(); i++) {
            if (i < 1 || nums[i] != nums[pos - 1]) {    // 注意这里pos-1处才存放上一个独立元素
                nums[pos] = nums[i];
                pos++;
            } 
        }
        return pos;
    }
};