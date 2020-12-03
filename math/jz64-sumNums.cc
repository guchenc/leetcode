/*
 * @Description: 求1+2+3+...+n 要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
 * @Author: guchen
 * @Date: 2020-12-03 15:56:15
 * @LastEditTime: 2020-12-03 15:57:00
 */
class Solution {
public:
    int sumNums(int n) {
        int sum = n;
        bool flag = n > 0 && (sum += sumNums(n - 1));    // 关键是利用&&短路特性，停止递归
        return sum;
    }
};