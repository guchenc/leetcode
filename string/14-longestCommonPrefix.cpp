/*
 * @Description: �����ǰ׺
 * @Author: guchen
 * @Date: 2020-09-19 17:06:03
 * @LastEditTime: 2020-09-19 17:07:23
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    // ���ַ������鿴����άchar���飬���н��бȽϣ���ĳ�е�β����ĳ����Ӧ�в�ƥ�����
    // time: O(minlen * n) minlenΪ�ַ�����������̵��ַ������ȣ�nΪ�ַ��������С space: O(1)
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        int nrow = strs.size();
        int ncol = strs[0].size();
        for (int j = 0; j < ncol; j++) {
            for (int i = 0; i < nrow; i++) {
                char c =strs[0][j];
                if (j == strs[i].size() || strs[i][j] != c)
                    return strs[0].substr(0, j);
            }
        }
        return strs[0];
    }
    // time: O(minlen * n) minlenΪ�ַ�����������̵��ַ������ȣ�nΪ�ַ��������С space: O(1)
    string longestCommonPrefix2(vector<string>& strs) {
        char cur;
        int index = 0;
        int minlen = INT_MAX;
        
        if (strs.empty())
            return "";  
        for (auto s : strs) {
            if (s.empty()) return "";   // ���ڿ��ַ�����ֱ�ӷ���ǰ׺""
            if (s.size() < minlen)  // ���޿��ַ�������¼����ַ�������
                minlen = s.size();
        }

        while (index < minlen) {
            cur = strs[0][index];   // ÿ��ȡ��һ���ַ�������Ӧλ�ý��бȽ�
            for (auto s : strs) {
                if (s[index] != cur)    // ����string��Ӧλ�ò�ͬ��������ȷ����prefix
                    return strs[0].substr(0, index);
            }
            index++;
        } // ������̵ķǿ��ַ������ǹ���ǰ׺
        return strs[0].substr(0, index);
    }
};