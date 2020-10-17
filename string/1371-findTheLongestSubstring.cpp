/*
 * @Description: 每个元音包含偶数次的最长子字符串
 * @Author: guchen
 * @Date: 2020-10-17 16:08:10
 * @LastEditTime: 2020-10-17 16:10:40
 */

#include "../alg.h"

class Solution {
public:

    int findTheLongestSubstring(string s) {
        vector<int> pre(32,INT_MAX);
        pre[0]=-1;
        const int N=s.size();
        int cur=0;
        int ans=0;
        for(int i=0;i<N;++i){
            switch(s[i]){
                case 'a':cur^=1;break;
                case 'e':cur^=2;break;
                case 'i':cur^=4;break;
                case 'o':cur^=8;break;
                case 'u':cur^=16;break;
                default:break;
            }
            if(pre[cur]==INT_MAX) pre[cur]=i;
            else ans=max(ans,i-pre[cur]);
        }
        return ans;
    }

    // 暴力解法 超时 time: O(n^2) space: O(1)
    int findTheLongestSubstring1(string s) {
        string vowels = "aeiou";
        int maxlen = 0;
        for (int i = 0; i < s.size(); i++) {
            int cnt[5] = {0};
            for (int j = i; j < s.size(); j++) {
                auto pos = vowels.find(s[j]);
                if (pos != string::npos) cnt[pos]++;
                bool flag = true;
                for (auto n : cnt) {
                    if (n % 2 != 0) {
                        flag = false;
                        break;
                    }
                }
                if (flag) maxlen = max(maxlen, j - i + 1);
            }
        }
        return maxlen;
    }
};