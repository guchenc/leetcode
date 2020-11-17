/*
 * @Description: 根据身高重建队列
 * @Author: guchen
 * @Date: 2020-11-17 19:20:09
 * @LastEditTime: 2020-11-17 19:20:52
 */
#include "../alg.h"
class Solution {
public:
    // 身高较矮的的人不会影响身高比其高的人的位置，优先排身高高的人的位置，当身高一致时，优先排k值小的
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int>> queue;
        sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
        });
        vector<int> pos;    // 根据索引存储people新队列，减少下面的插入复制性能损耗
        for (int i = 0; i < n; i++) {
            // 此时身高比当前元素高的人的位置已经排完，可以直接根据k值确定位置
            auto it = pos.begin() + people[i][1];
            pos.insert(it, i);   
        }
        for (auto idx : pos)  queue.push_back(people[idx]);
        return queue;
    }
    /*
    [4, 4]  [7, 0]
    [5, 0]  [7, 1]
    [5, 2]  [6, 1]
    [6, 1]  [5, 0]
    [7, 0]  [5, 2]
    [7, 1]  [4, 4]
    */
};