/*
 * @Description: 组合总和
 * @Author: guchen
 * @Date: 2020-09-18 22:09:49
 * @LastEditTime: 2020-09-18 22:23:22
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // DFS+回溯 time:  space: 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        if (candidates.empty())
            return res;
        // 找到数组中最小的数
        int min = *min_element(candidates.begin(), candidates.end());
        dfs(candidates, min, 0,target, ans, res);
        return res;
    }
    
    // 优化的回溯算法，关键在于如何剪枝避免重复
    // 用参数cur记录前一个位置放置的数，选择的下一个数必须小于等于target且必须大于cur
    void dfs(vector<int>& candidates, int min, int cur, int target, vector<int>& ans, vector<vector<int>>& res) {
        if (target < min) { // 当差值无法再次分解时，结束递归
            if (target == 0) {  // 有效解
                res.push_back(ans);
            }   // 无效解
            return;
        }
        for (int n : candidates) {
            if (n <= target && n >= cur) {
                ans.push_back(n);
                dfs(candidates, min, n, target - n, ans, res);
                ans.pop_back();
            }
        }
    }

    // 憨憨解法，费时费内存, 952ms 117mb也是np
    void dfs2(vector<int>& candidates, int min, int target, vector<int>& ans, vector<vector<int>>& res) {
        if (target < min) { // 当差值无法再次分解时，结束递归
            if (target == 0) {  // 有效解
                int exist = 0;
                vector<int> ent(ans);   // 这里必须创建ans的副本在进行排序，否则会更改ans元素的顺序，导致回溯出错
                sort(ent.begin(), ent.end());   // 先排序再在res中查找是否存在相同vector，若不存在再插入，效率低
                for (auto a : res) {
                    if (ent == a) { // vector已经重载了==
                        exist = 1;
                        break;
                    }
                }
                if (!exist)
                    res.push_back(ent);
            }   // 无效解
            return;
        }
        for (int n : candidates) {
            if (n <= target) {
                ans.push_back(n);
                dfs2(candidates, min, target - n, ans, res);
                ans.pop_back();
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> candidates;
    int n;
    int target;
    cin >> target;
    while (cin >> n) {
        candidates.push_back(n);
    }

    vector<vector<int>> res = s.combinationSum(candidates, target);
    for (auto v : res) {
        cout << "[";
        for (auto n : v) {
            cout << n << " ";
        }
        cout << "\b]" << endl;
    }
}