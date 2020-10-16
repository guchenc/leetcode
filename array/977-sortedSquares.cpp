/*
 * @Description: 有序数组的平方
 * @Author: guchen
 * @Date: 2020-10-16 09:47:03
 * @LastEditTime: 2020-10-16 09:56:39
 */
#include "../alg.h"

class Solution {
public:
    // time: O(n) space: O(n)
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());
        int l = 0, r = A.size() - 1, pos = r;
        while (l <= r) {
            int l2 = pow(A[l], 2);
            int r2 = pow(A[r], 2);
            if (l2 > r2) {
                res[pos--] = l2;
                l++;
            } else {
                res[pos--] = r2;
                r--;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-40, -15, -5, -3, 1, 6, 7, 19};
    vector<int> res = s.sortedSquares(nums);
    for (auto n : res) cout << n << " ";

}