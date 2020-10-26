/*
 * @Description: 数组中的最长山脉
 * @Author: guchen
 * @Date: 2020-10-25 21:42:16
 * @LastEditTime: 2020-10-25 21:45:40
 */
#include "../alg.h"

class Solution {
public:
    int longestMountain(vector<int>& A) {
        if (A.empty()) return 0;    // 如果不检查，A.size() - 1会溢出为INT64_MAX
        int maxlen = 0;
        int i = 1, l, r = 1;
        while (i < A.size() - 1) {
            if (A[i - 1] < A[i] && A[i + 1] < A[i]) {
                l = i - 1, r = i + 1;
                while (l - 1 >= 0 && A[l - 1] < A[l]) l--;
                while (r + 1 < A.size() && A[r + 1] < A[r]) r++;
                maxlen = max(maxlen, r - l + 1);
                i = r + 1;  // 从前一个峰脚继续遍历，加快速度
                continue;
            }
            i++;
        }
        return maxlen;
    }
    // time: O(n) space: O(1)
    int longestMountain4(vector<int>& A) {
        int maxlen = INT_MIN;
        int i = 0;
        while (i < A.size()) {
            if (i - 1 < 0 || i + 1 >= A.size() || A[i - 1] >= A[i] || A[i + 1] >= A[i]) {
                i++;
                continue;
            } 
            int l = i, r = i, len = 1;
            while (l - 1 >= 0 && A[l - 1] < A[l]) l--, len++;
            while (r + 1 < A.size() && A[r + 1] < A[r]) r++, len++;
            if (len >= 3 && l != i && r != i) maxlen = max(maxlen, len);
            i = r + 1;
        }
        return maxlen == INT_MIN ? 0 : maxlen;
    }

    // 优化，若存在峰，记录峰脚，下次从峰脚之后开始
    int longestMountain3(vector<int>& A) {
        if (A.size() < 3) return 0;
        int maxlen = INT_MIN;
        int foot;
        for (int i = 1; i < A.size() - 1; i = foot + 1) 
            maxlen = max(maxlen, expand(A, i, &foot));
        return maxlen == INT_MIN ? 0 : maxlen;
    }

    int expand(vector<int>& A, int mid, int* foot) {
        int len = 1;
        int l = mid, r = mid;
        while (l - 1 >= 0 && A[l - 1] < A[l]) l--, len++;
        while (r + 1 < A.size() && A[r + 1] < A[r]) r++, len++;
        // cout << len << endl;
        *foot = r;
        return len >= 3 && mid != l && mid != r ? len : 0;
    }

    // 以每个位置作为山峰向两边扩展 time: O(?)  space: O(1)
    int longestMountain2(vector<int>& A) {
        if (A.size() < 3) return 0;
        int maxlen = INT_MIN;
        for (int i = 0; i < A.size(); i++) 
            maxlen = max(maxlen, expand(A, i));
        return maxlen == INT_MIN ? 0 : maxlen;
    }

    int expand(vector<int>& A, int mid) {
        int len = 1;
        int l = mid, r = mid;
        while (l - 1 >= 0 && A[l - 1] < A[l]) l--, len++;
        while (r + 1 < A.size() && A[r + 1] < A[r]) r++, len++;
        // cout << len << endl;
        return len >= 3 && mid != l && mid != r ? len : 0;
    }

    // 写不出来，憨憨解法
    int longestMountain1(vector<int>& A) {
        int maxlen = INT_MIN;
        int len;
        bool up = true;
        for (int i = 0; i < A.size() - 1; i++) {
            len = 1;
            for (int j = i + 1; j < A.size(); j++) {
                if (A[j] == A[j - 1]) {
                } 
                else if (A[j] > A[j - 1]) len++;
                else {
                    if (up) {
                        if (len == 1) break;
                        up = false;
                    } else{
                        len++;
                    }
                }
            }
        }
        return maxlen;
    }
};