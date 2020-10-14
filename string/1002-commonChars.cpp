/*
 * @Description: 查找常用字符
 * @Author: guchen
 * @Date: 2020-10-14 09:29:18
 * @LastEditTime: 2020-10-14 09:29:42
 */
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        int charcnt[26] = {0};
        for (int j = 0; j < A[0].size(); j++)   // 以第一个字符串为基准，统计26个字母的出现情况
            charcnt[A[0][j] - 'a'] += 1;
        for (int i = 1; i < A.size(); i++) {    
            int cnt[26] = {0};
            for (int j = 0; j < A[i].size(); j++)   // 针对后面每个字符串统计其字母频率
                cnt[A[i][j] - 'a'] += 1;
            for (int k = 0; k < 26; k++)    // 更新字母频率为最小值
                charcnt[k] = min(charcnt[k], cnt[k]);
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < charcnt[i]; j++)
                res.emplace_back(1, 'a' + i);
        }
        return res;
    }
};