/*
 * @Description: 独一无二的出现次数
 * @Author: guchen
 * @Date: 2020-10-28 20:56:41
 * @LastEditTime: 2020-10-28 20:56:52
 */
#include "../alg.h"
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_set<int> s;
        int i = 0;
        while (i < arr.size()) {
            int temp = arr[i];
            int cnt = 1;
            while (i + 1 < arr.size() && arr[i + 1] == temp) {
                cnt++;
                i++;
            }
            auto it = s.find(cnt);
            if (it != s.end()) return false;
            s.insert(cnt);
            i++;
        }
        return true;
    } 
};