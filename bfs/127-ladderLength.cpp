/*
 * @Description: 单词接龙I
 * @Author: guchen
 * @Date: 2020-11-06 16:54:46
 * @LastEditTime: 2020-11-06 16:55:10
 */
#include "../alg.h"
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> sb, se;
        unordered_set<string> visited;
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end()) return 0;
        sb.insert(beginWord);
        se.insert(endWord);
        int cnt = 1, wordlen = beginWord.size();
        while (!sb.empty() && !se.empty()) {
            auto& small = sb.size() > se.size() ? se : sb;
            auto& bigger = sb.size() > se.size() ? sb : se;
            unordered_set<string> next;
            for (auto it = small.begin(); it != small.end(); it++) {
                string cur = *it;
                if (bigger.find(cur) != bigger.end()) return cnt;
                visited.insert(cur);
                for (int j = 0; j < wordlen; j++) {
                    char tmp = cur[j];
                    for (int k = 0; k < 26; k++) {
                        if ('a' + k == tmp) continue;
                        cur[j] = 'a' + k;
                        if (words.find(cur) == words.end() || visited.find(cur) != visited.end()) continue;
                        next.insert(cur);
                    }
                    cur[j] = tmp;
                }
            }
            small.swap(next);
            cnt++;
        }
        return 0;
    }
};