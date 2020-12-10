/*
 * @Description: 表示数值的字符串
 * @Author: guchen
 * @Date: 2020-12-10 20:31:17
 * @LastEditTime: 2020-12-10 20:31:37
 */
#include "../alg.h"
class Solution {
public:
    // '.'出现正确情况：只出现一次，且在e的前面
    // 'e'出现正确情况：只出现一次，且出现前有数字
    // '+/-'出现正确情况：只能在开头和e后一位
    bool isNumber(string s) {
        auto begin = s.find_first_not_of(' ');
        auto end = s.find_last_not_of(' ');
        if (begin == string::npos) return false;
        bool numFlag = false, dotFlag = false, expFlag = false;
        for (int i = begin; i <= end; i++) {
            if (isdigit(s[i])) numFlag = true;
            else if (s[i] == '.' && !dotFlag && !expFlag) dotFlag = true;   // 还没有出现. 和 e/E
            else if ((s[i] == 'e' || s[i] == 'E') && !expFlag && numFlag) { // 还没有出现e/E 但是已经出现了数字
                numFlag = false;
                expFlag = true;
            } else if ((s[i] == '+' || s[i] == '-') && (i == begin || s[i - 1] == 'e' || s[i - 1] == 'E')) {
                ;
            } else return false;    // 其他情况全部错误
        }
        // numFlag: 来到这一步只需要判断数字的情况，因为. e/E +/- 的位置都已经按照符合要求的情况放置了
        // - 没有出现e/E: 出现了数字返回true，没有出现数字返回false
        // - 出现e/E: numFlag被置为false，必须保证e/E之后又出现了数字 “-1.2e+”就不符合条件
        return numFlag;
    }

    enum state {FRONT_BLANK, INT_SIGN, INT, DOT_LEFT_INT, DOT_LEFT_NOINT, FRACTION, EXP, EXP_SIGN, EXP_INT, BACK_BLANK};
    enum charType {BLANK, DIGIT, DOT, E, SIGN, INVALID};
    unordered_map<state, unordered_map<charType, state>> transfer = {
        {
            FRONT_BLANK, {
                {BLANK, FRONT_BLANK},
                {DIGIT, INT},
                {DOT, DOT_LEFT_NOINT},
                {SIGN, INT_SIGN}
            },
        },
        {
            INT_SIGN, {
                {DIGIT, INT},
                {DOT, DOT_LEFT_NOINT},
            },
        },
        {
            INT, {
                {DIGIT, INT},
                {DOT, DOT_LEFT_INT},
                {E, EXP},
                {BLANK, BACK_BLANK}
            },
        },
        {
            DOT_LEFT_INT, {
                {DIGIT, FRACTION},
                {E, EXP},
                {BLANK, BACK_BLANK}
            },
        },
        {
            DOT_LEFT_NOINT, {
                {DIGIT, FRACTION},
            },
        },
        {
            FRACTION, {
                {DIGIT, FRACTION},
                {E, EXP},
                {BLANK, BACK_BLANK}
            },
        },
        {
            EXP, {
                {SIGN, EXP_SIGN},
                {DIGIT, EXP_INT}
            },
        },
        {
            EXP_SIGN, {
                {DIGIT, EXP_INT},
            },
        },
        {
            EXP_INT, {
                {DIGIT, EXP_INT},
                {BLANK, BACK_BLANK}
            },
        },
        {
            BACK_BLANK, {
                {BLANK, BACK_BLANK}
            },
        }
    };
    charType getType(char c) {
        if (isdigit(c)) return DIGIT;
        else if (c == ' ') return BLANK;
        else if (c == 'e' || c == 'E') return E;
        else if (c == '-' || c == '+') return SIGN;
        else if (c == '.') return DOT;
        return INVALID;
    }

    string print_state(state s) {
        switch(s) {
            case FRONT_BLANK: return "FRONT_BLANK";
            case INT_SIGN: return "INT_SIGN";
            case INT: return "INT";
            case DOT_LEFT_INT: return "DOT_LEFT_INT";
            case DOT_LEFT_NOINT: return "DOT_LEFT_NOINT";
            case FRACTION: return "FRANCTION";
            case EXP: return "EXP";
            case EXP_SIGN: return "EXP_SIGN";
            case EXP_INT: return "EXP_INT";
            case BACK_BLANK: return "BACK_BLANK";
        }
        return "INVALID";
    }

    // 确认有限状态自动机 DFA
    bool isNumber2(string s) {
        state cur_state = FRONT_BLANK;
        for (int i = 0; i < s.size(); i++) {
            charType t = getType(s[i]);
            unordered_map<charType, state>& next_state = transfer[cur_state];
            if (next_state.find(t) == next_state.end()) return false;   // 碰到无法转换的情况直接返回false，说明不符合转换规则
            // cout << "cur:" << print_state(cur_state) << " " << s[i] <<  " next:" << print_state(next_state[t])  << endl;
            cur_state = next_state[t];
        }
        return cur_state == INT || cur_state == DOT_LEFT_INT || cur_state == FRACTION || cur_state == EXP_INT || cur_state == BACK_BLANK;      
    }

    // 设置flag, 巧妙的方法   time: O(n) space: O(1)
    bool isNumber1(string s) {
        if (s.empty()) return false;
        // 相当于trim(),去除字符串首尾空格
        int begin = s.find_first_not_of(" ");
        int end = s.find_last_not_of(" ");
        if (begin == string::npos) return false;
        bool numFlag = false, dotFlag = false, eFlag = false;
        for (int i = begin; i <= end; i++) {
            if (isdigit(s[i])) numFlag = true;
            else if (s[i] == '.' && !dotFlag && !eFlag) dotFlag = true; // 之前没有出现 . 和 e/E，.只可能位于e/E前
            else if ((s[i] == 'e' || s[i] == 'E') && !eFlag && numFlag) {
                eFlag = true;
                numFlag = false;  // avoid case like "123e"
            } else if ((s[i] == '+' || s[i] == '-') && (i == begin || s[i - 1] == 'e' || s[i - 1] == 'E')) {
                // +/- 只能出现在字符串最开始，或者e/E的后面
                ;
            } else return false;    // 其他情况都是错的
        }
        //首先不管哪种情况都必须要有数字，没有数字肯定不对
        // 其次对于存在 e 的情况，接收到 e 时已经判断前面有数字了，并将 numFlag 重置，意味着当接收到 e 后，如果后面没有数字（没有将 numFlag 重新标记为真），那么也是不对的。
        // numFlag: 来到这一步只需要判断数字的情况，因为. e/E +/- 的位置都已经按照符合要求的情况放置了
        // - 没有出现e/E: 出现了数字返回true，没有出现数字返回false
        // - 出现e/E: numFlag被置为false，必须保证e/E之后又出现了数字 “-1.2e+”就不符合条件
        return numFlag; 
    }
};