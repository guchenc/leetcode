/*
 * @Description: 杨辉三角II
 * @Author: guchen
 * @Date: 2020-10-14 19:30:10
 * @LastEditTime: 2020-10-14 19:30:32
 */
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        if (rowIndex == 1) return {1, 1};
        vector<int> row = {1, 1};
        vector<int> nrow;
        for (int i = 2; i <= rowIndex; i++) {
            nrow.emplace_back(1);
            for (int j = 1; j < row.size(); j++)
                nrow.emplace_back(row[j - 1] + row[j]);
            nrow.emplace_back(1);
            row.assign(nrow.begin(), nrow.end());
            nrow.clear();
        }
        return row;

    }
};