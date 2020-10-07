/*
 * @Description: 颜色分类
 * @Author: guchen
 * @Date: 2020-10-07 17:54:41
 * @LastEditTime: 2020-10-07 17:55:17
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // 一遍扫描法 time: O(n) space: O(1)
    // - 维护两个下标rp,b; rp指向下一个放置0的位置，bp指向下一个放置2的位置; 
    // - 遍历一边数组
    //    - 当遇到0时，交换nums[i]与nums[rp],右移rp，考察下一位置;
    //    - 当遇到1时，直接考察下一位置,不管1，因为当0和2位于正确位置时，1一定在正确位置上
    //    - 当遇到2时，交换nums[i]与nums[bp]，左移bp，考察下一位置;
    //    - 当i > bp时，跳出循环，因为此时后面的元素都已经为2了
    void sortColors(vector<int>& nums) {
        int rp = 0, bp = nums.size() - 1;
        int i = 0;
        while (i < nums.size()) {
            if (i > bp) break;
            if (nums[i] == 0) {
                swap(nums[i], nums[rp]);
                i++;
                rp++;
            } else if (nums[i] == 1) {
                i++;
            } else {
                swap(nums[i], nums[bp]);
                bp--;
            }
        }
    }

    void print(int rp, int bp, vector<int>& nums) {
        cout << "rp:" << rp << " bp:" << bp << " [";
        for (int i = 0; i < nums.size(); i++)
            cout << nums[i] << " ";
        cout << "]" << endl;
    }

    // 遍历两遍数组，第一遍统计各颜色数量，第二遍按照红白蓝色顺序原地输出 time: O(n) space: O(1)
    void sortColors1(vector<int>& nums) {
        int rcnt = 0, wcnt = 0, bcnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) rcnt++;
            else if (nums[i] == 1) wcnt++;
            else bcnt++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (rcnt-- > 0) nums[i] = 0;
            else if (wcnt-- > 0) nums[i] = 1;
            else if (bcnt-- > 0) nums[i] = 2;
         }
    }
};