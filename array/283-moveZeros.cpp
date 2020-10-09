/*
 * @Description: 移动零
 * @Author: guchen
 * @Date: 2020-10-09 14:05:13
 * @LastEditTime: 2020-10-09 14:09:35
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 维护一个数组下标，其指向下一个放置非0数字的位置，遍历完整个数组，碰到非0数字就将其与pos位置上的数字交换，随后pos++
    // time: O(n) space: O(1)
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[pos], nums[i]);
                pos++;
            }
        }
    }

    // 维护一个数组下标，其指向下一个放置非0数字的位置，遍历完整个数组，碰到非0数字将其赋值给pos位置上的数字，之后将当前数字置为0,pos++
    // time: O(n) space: O(1)
    void moveZeroes1(vector<int>& nums) {
        int pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[pos] = nums[i];
                // if (i != pos) nums[i] = 0;
                pos++;
            }
        }
        for (int i = pos; i < nums.size(); i++)
            nums[i] = 0;
    }
};