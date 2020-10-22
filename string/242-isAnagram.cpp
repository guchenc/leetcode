/*
 * @Description: 有效的字母异位词
 * @Author: guchen
 * @Date: 2020-10-22 16:03:17
 * @LastEditTime: 2020-10-22 16:03:36
 */
#include "../alg.h"
class Solution {
public:
    // time: O(n) space: O(1)
    // 字符串中只有小写字母，用大小26的整形数组统计字符出现次数
    // - 字符串s中的字符+1
    // - 字符串t中的字符-1
    // 若为字母异位词，每个位置都是0
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int alpha[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            alpha[s[i] - 'a']++;
            alpha[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (alpha[i] != 0) return false;
        return true;
    }

    // 直接排序比较 time: O(nlogn) space: O(1)
    bool isAnagram2(string s, string t) {
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < s.size(); i++) 
            if (s[i] != t[i]) return false;
        return true;
    }

    // 借助multiset的自动排序功能，time: O(n) space: O(n)
    // - 若两个字符串长度不等，返回false
    // - 遍历字符串，将两个字符串对应位置不相等的字符分别添加到各自的set
    // - 由于set自带排序，因此迭代器遍历时结果是按照字典顺序排列的，直接比较
    bool isAnagram1(string s, string t) {
        if (s.size() != t.size()) return false;
        multiset<char> ss, ts;  // 底层基于红黑树实现，自带排序
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                ss.insert(s[i]);
                ts.insert(t[i]);
            }
        }
        return equal(ss.begin(), ss.end(), ts.begin(), ts.end());
    }
};