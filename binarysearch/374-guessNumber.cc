/*
 * @Description: 猜数字大小
 * @Author: guchen
 * @Date: 2020-11-25 15:12:33
 * @LastEditTime: 2020-11-25 15:13:03
 */
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int mid);
class Solution {
public:
    // 二分查找 time: O(logn) space: O(1)
    int guessNumber(int n) {
        int res;
        int l = 1, r = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int rc = guess(mid);
            if (rc == -1) r = mid - 1;
            else if (rc == 1) l = mid + 1;
            else return mid;
        }
        return -1;
    }
};