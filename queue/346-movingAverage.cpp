/*
 * @Description: 数据流中的移动平均值
 * @Author: guchen
 * @Date: 2020-09-27 11:19:43
 * @LastEditTime: 2020-09-27 12:16:14
 */
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public: 
    vector<int> data;
    queue<int> window;
    int wdsize;

    Solution(int size, vector<int>& src) {
        data = src;
        wdsize = size;
    } 

    double next(int n) {
        if (window.size() == wdsize)
            window.pop();
        window.push(n);
        double sum = 0.0, size = window.size();
        for (int i = 0; i < size; i++) {
            int val = window.front();
            sum += val;
            window.pop();
            window.push(val);
        }
        return sum / size;
    }
};

int main() {
    vector<int> nums;
    int num;
    while (cin >> num)
        nums.push_back(num);
    Solution s(3, nums);
    cout.precision(2);
    cout.setf(ios::fixed);
    for (int i = 0; i < nums.size(); i++)
        cout << s.next(nums[i]) << " ";
    return 0;
}



