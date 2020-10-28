/*
 * @Description: 字母异位词分组
 * @Author: guchen
 * @Date: 2020-10-28 20:52:59
 * @LastEditTime: 2020-10-28 20:53:16
 */
#include "../alg.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            auto it = m.find(temp);
            if (it != m.end()) m[temp].push_back(strs[i]);
            else m[temp] = {strs[i]};
        }
        for (auto it = m.begin(); it != m.end(); it++)
            res.emplace_back(it->second);
        return res;
    }
};