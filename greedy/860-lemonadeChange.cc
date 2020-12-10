/*
 * @Description: 柠檬水找零
 * @Author: guchen
 * @Date: 2020-12-10 20:26:46
 * @LastEditTime: 2020-12-10 20:27:04
 */
#include "../alg.h"
class Solution {
public:
    // 同1，不需要哈希表
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (auto b : bills) {
            if (b == 5) five++;
            else if (b == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            } else {
                bool ok = false;
                // 贪心 优先大面额找零，避免手中只有大面额，无法找小面额的场景 5,5,5,10  20 10
                if (five > 0 && ten > 0) {  
                    five--;
                    ten--;
                    ok = true;
                } else if (five > 3) {
                    five -= 3;
                    ok = true;
                } 
                if (!ok) return false;
            }
        }
        return true;
    }
    
    // 贪心 优先用大面额找零 time: O(n) space: O(1)
    bool lemonadeChange1(vector<int>& bills) {
        unordered_map<int, int> cash;
        cash[5] = 0, cash[10] = 0, cash[20] = 0;
        for (auto b : bills) {
            if (b == 5) cash[5]++;
            else if (b == 10) {
                if (cash[5] == 0) return false;
                cash[5]--;
                cash[10]++;
            } else {
                bool ok = false;
                if (cash[5] > 0 && cash[10] > 0) {
                    cash[5]--;
                    cash[10]--;
                    ok = true;
                } else if (cash[5] >= 3) {
                    cash[5] -= 3;
                    ok = true;
                }
                if (!ok) return false;
                cash[20]++;
            }
        }
        return true;
    }
};