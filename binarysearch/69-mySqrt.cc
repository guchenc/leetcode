/*
 * @Description: x的平方根
 * @Author: guchen
 * @Date: 2020-11-25 15:13:37
 * @LastEditTime: 2020-11-25 15:14:12
 */
class Solution {
public:
    // 牛顿迭代法
    int mySqrt(int x) {
        // TODO
    }

    // 二分查找 x的平方根K是满足k^2 <= x的最大k值 time: O(logn) space: O(1)
    int mySqrt(int x) {
        int l = 0, r = x;
        int res = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long mid2 = (long long)mid * mid;
            if (mid2 <= x) {
                res = mid;
                l = mid + 1;
            } else r = mid - 1;
            // int mid = l + (r - l) / 2;
            // if (pow(mid, 2) <= x) { // pow返回值为double，x为int，两者可以直接比较，x会自动转换为double类型之后再进行比较
            //     res = mid;
            //     l = mid + 1;
            // } else {
            //     r = mid - 1;
            // }
        }
        return res;
    }
};