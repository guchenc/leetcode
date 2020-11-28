/*
 * @Description: 找到K个最接近的元素
 * @Author: guchen
 * @Date: 2020-11-28 17:17:21
 * @LastEditTime: 2020-11-28 17:17:30
 */
#include "../alg.h"
class Solution {
public:
    // 双指针选择从两边依次删除元素，直到剩余k个元素 time: O(n) space: O(1)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - 1;
        while (r - l + 1 != k) {
            int ldis = abs(arr[l] - x);
            int rdis = abs(arr[r] - x);
            if (ldis > rdis) l++;
            else if (ldis < rdis) r--;
            else r--;
        }
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }

    vector<int> findClosestElements4(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - k;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (x - arr[m] > arr[m + k] - x) l = m + 1;
            else r = m;
        }
        return vector<int>(arr.begin() + l, arr.begin() + k + l);
    }

    vector<int> findClosestElements3(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [x](int u, int v) {
            return abs(u - x) < abs(v - x) || (abs(u - x) == abs(v - x) && u <= v);
        });
        sort(arr.begin(), arr.begin() + k);
        return vector<int>(arr.begin(), arr.begin() + k);
    }

    // 有问题 time: O(logn) space: O(0)
    vector<int> findClosestElements2(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - 1;
        int idx = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] > x) r = m - 1;
            else if (arr[m] < x) l = m + 1;
            else {
                l = m;
                break;
            }
        }
        idx = l;    // 此时dix为最接近x的元素下标
        l = r = idx;
        int cnt = 0, ldis, rdis;
        while (cnt < k) {
            ldis = l >= 0 ? abs(arr[l] - x) : INT_MAX;
            rdis = r < arr.size() ? abs(arr[r] - x) : INT_MAX;
            if (ldis <= rdis) l--;
            else r++;
            cnt++;
        }
        return vector<int>(arr.begin() + l + 1, arr.begin() + r);   //(l, r)
    }

    vector<int> findClosestElements1(vector<int>& arr, int k, int x) {
        deque<int> deq;
        int l = 0, r = arr.size() - 1;
        int idx = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] > x) r = m - 1;
            else if (arr[m] < x) l = m + 1;
            else {
                l = m;
                break;
            }
        }
        idx = l;
        l = idx - 1, r = idx;
        int cnt = 0;
        // cout << l << " " << r << endl;
        while (cnt < k) {
            if (l < 0) {
                while (cnt++ < k)
                    deq.push_back(arr[r++]);
                return vector<int>(deq.begin(), deq.end());
            }

            if (r >= arr.size()) {
                while (cnt++ < k)
                    deq.push_front(arr[l--]);
                return vector<int>(deq.begin(), deq.end());
            }
            int ldis = abs(arr[l] - x);
            int rdis = abs(arr[r] - x);
            if (ldis <= rdis) {
                deq.push_front(arr[l]);
                cnt++;
                l--;
            } else {
                deq.push_back(arr[r]);
                cnt++;
                r++;
            }
        }
        return vector<int>(deq.begin(), deq.end());
    }
};