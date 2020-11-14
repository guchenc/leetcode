/*
 * @Description: 数组的相对排序
 * @Author: guchen
 * @Date: 2020-11-14 17:43:03
 * @LastEditTime: 2020-11-14 17:43:30
 */
#include "../alg.h"
class Solution {
public:
    // 因为数组元素大小限定在[0, 1000]，所以可以使用一个固定大小的数组存储频率 time: O(n) n为arr1大小 space: O(1)
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res(arr1.size());
        int frequency[1001] = {0};
        int idx = 0;
        for (int i = 0; i < arr1.size(); i++) frequency[arr1[i]]++;
        for (int i = 0; i < arr2.size(); i++) {
            int cur = arr2[i];
            int cnt = frequency[cur];
            while (cnt-- > 0) res[idx++] = cur;
            frequency[cur] = 0;
        }
        for (int i = 0; i < 1001; i++) {    // 处理没有出现在arr2中的元素
            int cnt = frequency[i];
            if (cnt == 0) continue;
            while (cnt-- > 0) res[idx++] = i;
        }
        return res;

    }
    // map time: O(n) n为arr1大小 space: O(n)
    vector<int> relativeSortArray1(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;
        for (int i = 0; i < arr1.size(); i++) {
            if (m.find(arr1[i]) == m.end()) m[arr1[i]] = 1;
            else m[arr1[i]] += 1;
        }
        int idx = 0;
        for (int i = 0; i < arr2.size(); i++) {
            int cnt = m[arr2[i]];
            while (cnt-- > 0) arr1[idx++] = arr2[i];
            m[arr2[i]] = 0;
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            int cnt = it->second;
            while (cnt-- > 0) arr1[idx++] = it->first;
        }
        return arr1;

    }
};
