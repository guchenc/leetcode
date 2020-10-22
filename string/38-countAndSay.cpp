/*
 * @Description: 外观数列
 * @Author: guchen
 * @Date: 2020-10-22 16:02:07
 * @LastEditTime: 2020-10-22 16:02:18
 */
#include "../alg.h"

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        int index = 1;
        while (index != n) {
            string temp;
            for (int i = 0; i < res.size();) {
                char c = res[i];
                int cnt = 0;
                while (i < res.size() && res[i] == c) {
                    cnt++;
                    i++;   
                } 
                temp += '0' + cnt;
                temp += c;
            }
            swap(res, temp);
            index++;
        }
        return res;    
    }
};