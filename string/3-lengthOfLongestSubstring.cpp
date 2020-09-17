/*
 * @Description: ���ظ��ַ�����Ӵ�
 * @Author: guchen
 * @Date: 2020-09-17 20:06:36
 * @LastEditTime: 2020-09-17 23:08:46
 */
#include <unordered_map>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    string maxsubstr;
    // ˫ָ�� time: O(n) space: O(n)
    // - ˳����������ַ��������±���: start(��ǰ�����Ӵ�����ʼ�±�) curlen(��ǰ�����Ӵ��ĳ���) maxlen(���ظ���Ӵ�����) map m(��¼��ǰ�����Ӵ��г��ֹ����ַ����ϼ�����Ӧ�±�)
    // - �����ǰ�����Ӵ���û�г��ֹ���ǰ���������ַ��������ַ��������ַ����е��±����map
    // - �����ǰ�����Ӵ��г��ֹ���ǰ���������ַ������ϴγ��ֵ��±�Ϊpos
    //      * ���㵱ǰ�Ӵ��ĳ���(i - start)������maxlen
    //      * ��[start, pos]�е��ַ���map��ɾ��
    //      * ����ǰ���������ַ�(���ظ����ֵ��ַ�)�����±���뵽map
    //      * ����startΪpos + 1, �������������ַ����ظ���������
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int i, start = 0, maxlen = 0, curlen;
        for (i = 0; i < s.size(); i++) {
            auto itr = m.find(s[i]);
            if (itr == m.end()) {
                m.insert(make_pair(s[i], i));
                // cout << "+ <" << s[i] << "," << i << ">" << endl;
            } else {
                curlen = i - start;
                if (curlen > maxlen) {
                    maxsubstr = s.substr(start, curlen);
                    maxlen = curlen;
                }
                int pos = itr->second;
                // cout << "start=" << start << " pos=" << pos << " i=" << i << endl;
                for (int j = start; j <= pos; j++) {
                    // cout << "- <" << s[j] << "," << m.find(s[j])->second << ">" << endl;
                    m.erase(s[j]);
                }
                m.insert(make_pair(s[i], i));   // ���ظ��ַ���Ϊ�µ��ַ�����map
                start = pos + 1;    // ���Ӵ��Ӿɵ��ظ��ַ��ĺ�һλ��ʼ
            }
        }
        curlen = i - start;
        if (curlen > maxlen) {
            maxsubstr = s.substr(start, curlen);
            maxlen = curlen;
        }
        return maxlen;
    }

    // �����ⷨ time: O(n^2) space: O(n)
    // - ���ַ����ĵ�һ���ַ�Ϊ�Ӵ���ʼ�ַ���������
    // - ������δ���ֹ����ַ�ʱ���������set��������ǰ�ִ����ȼ�һ;
    // - ���������ֹ����ַ�ʱ���Ƚϵ�ǰ�ִ��������¼������ִ����Ȳ���������ִ����ȣ�����һ���ַ�Ϊ��ʼ�ַ�������������
    int lengthOfLongestSubstring1(string s) {
        set<char> chars;
        int maxlen = 0, cur_len;
        for (int i = 0; i < s.size(); i++) {
            cur_len = 0;
            chars.clear();
            for (int j = i; j < s.size(); j++) {
                auto itr = chars.find(s[j]);
                if (itr == chars.end()) {
                    chars.insert(s[j]);
                    cur_len += 1;
                } else {
                    break;
                }
            }
            if (cur_len > maxlen)
                maxlen = cur_len;
        }
        return maxlen;
    }
};

int main()
{
    Solution s;
    string str;
    int maxlen;
    while (getline(cin, str)) {
        maxlen = s.lengthOfLongestSubstring(str);
        cout << str << " : " << s.maxsubstr << "(" << maxlen << ")" << endl;
    }
}