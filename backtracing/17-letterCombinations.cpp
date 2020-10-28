/*
 * @Description: 电话号码的字母组和
 * @Author: guchen
 * @Date: 2020-10-28 20:45:45
 * @LastEditTime: 2020-10-28 20:46:04
 */
#include "../alg.h"

class Solution {
public:
    vector<string> res;
    unordered_map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return res;
        string word(digits.size(), '-');
        typeword(digits, 0, word);
        return res;
    }

    void typeword(string& digits, int idx, string& word) {
        if (idx == digits.size()) {
            res.push_back(word);
            return;
        }
        for (auto& c : m[digits[idx]]) {
            word[idx] = c;
            typeword(digits, idx + 1, word);
        }
    }
};