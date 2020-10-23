/*
 * @Description: 字符串转整数
 * @Author: guchen
 * @Date: 2020-10-23 17:24:41
 * @LastEditTime: 2020-10-23 17:24:50
 */
#include "../alg.h"
class Solution {
public:
    enum stat : int {
        STARTED, SIGN, NUM, END
    };
    // 动态机 
    int myAtoi(string s) {
        int idx = 0;
        bool positive = true;
        int res = 0;
        enum stat state = STARTED;
        while (idx < s.size() && state != END) {
            switch (state) {
                case STARTED:
                    if (s[idx] == ' ') {
                        idx++;
                    } else if (isdigit(s[idx])) {
                        res += s[idx] - '0';
                        idx++;
                        state = NUM;
                    } else if (s[idx] == '+' || s[idx] == '-'){
                        if (s[idx] == '-') positive = false;
                        state = SIGN;
                        idx++;
                    } else state = END;
                    break;
                case SIGN:
                    if (isdigit(s[idx])) {
                        res += s[idx] - '0';
                        idx++;
                        state = NUM;
                    } else state = END;
                    break;
                case NUM:
                    if (isdigit(s[idx])) {
                        int n = s[idx] - '0';
                        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && n > 7)) {
                            state = END;
                            return positive ? INT_MAX : INT_MIN;
                        } else {
                            res = res * 10 + n;
                            idx++;
                        }
                    } else state = END;
            }
        }
        return positive ? res : -res;
    }

    // 常规做法 只考虑符合条件的情况！！！！ time: O(n) space: O(1)
    int myAtoi1(string s) {
        int sum = 0;
        int flag = 1;
        int i = 0;
        while (s[i] == ' ') i++;
        if (s[i] == '-') flag = 0;
        if (s[i] == '-' || s[i] == '+') i++;
        while (i < s.size() && isdigit(s[i])) {
            int n = s[i] - '0';
            // if (sum > INT_MAX / 10 || sum > INT_MAX / 10 - n) return flag == 1 ? INT_MAX : INT_MIN;
            if (sum > INT_MAX / 10 || (sum == INT_MAX / 10 && n > 7)) return flag == 1 ? INT_MAX : INT_MIN;
            sum = sum * 10 + n;
            i++;
        }
        return flag == 1 ? sum : -sum;
    }
};