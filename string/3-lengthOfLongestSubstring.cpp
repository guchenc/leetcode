/*
 * @Description: 无重复字符的最长子串
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
    // 双指针 time: O(n) space: O(n)
    // - 顺序遍历整个字符串，更新变量: start(当前分析子串的起始下标) curlen(当前分析子串的长度) maxlen(无重复最长子串长度) map m(记录当前分析子串中出现过的字符集合及其相应下标)
    // - 如果当前分析子串中没有出现过当前遍历到的字符，将该字符及其在字符串中的下标插入map
    // - 如果当前分析子串中出现过当前遍历到的字符，记上次出现的下标为pos
    //      * 计算当前子串的长度(i - start)，更新maxlen
    //      * 将[start, pos]中的字符从map中删除
    //      * 将当前遍历到的字符(即重复出现的字符)及其下标插入到map
    //      * 更新start为pos + 1, 继续遍历后续字符，重复上述步骤
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
                m.insert(make_pair(s[i], i));   // 将重复字符作为新的字符插入map
                start = pos + 1;    // 新子串从旧的重复字符的后一位开始
            }
        }
        curlen = i - start;
        if (curlen > maxlen) {
            maxsubstr = s.substr(start, curlen);
            maxlen = curlen;
        }
        return maxlen;
    }

    // 暴力解法 time: O(n^2) space: O(n)
    // - 以字符串的第一个字符为子串起始字符，向后遍历
    // - 当遇到未出现过的字符时，将其加入set，并将当前字串长度加一;
    // - 当遇到出现过的字符时，比较当前字串长度与记录的最大字串长度并更新最大字串长度，以下一个字符为起始字符继续上述步骤
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