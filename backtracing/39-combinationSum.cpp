/*
 * @Description: ����ܺ�
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
    // DFS+���� time:  space: 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        if (candidates.empty())
            return res;
        // �ҵ���������С����
        int min = *min_element(candidates.begin(), candidates.end());
        dfs(candidates, min, 0,target, ans, res);
        return res;
    }
    
    // �Ż��Ļ����㷨���ؼ�������μ�֦�����ظ�
    // �ò���cur��¼ǰһ��λ�÷��õ�����ѡ�����һ��������С�ڵ���target�ұ������cur
    void dfs(vector<int>& candidates, int min, int cur, int target, vector<int>& ans, vector<vector<int>>& res) {
        if (target < min) { // ����ֵ�޷��ٴηֽ�ʱ�������ݹ�
            if (target == 0) {  // ��Ч��
                res.push_back(ans);
            }   // ��Ч��
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

    // �����ⷨ����ʱ���ڴ�, 952ms 117mbҲ��np
    void dfs2(vector<int>& candidates, int min, int target, vector<int>& ans, vector<vector<int>>& res) {
        if (target < min) { // ����ֵ�޷��ٴηֽ�ʱ�������ݹ�
            if (target == 0) {  // ��Ч��
                int exist = 0;
                vector<int> ent(ans);   // ������봴��ans�ĸ����ڽ������򣬷�������ansԪ�ص�˳�򣬵��»��ݳ���
                sort(ent.begin(), ent.end());   // ����������res�в����Ƿ������ͬvector�����������ٲ��룬Ч�ʵ�
                for (auto a : res) {
                    if (ent == a) { // vector�Ѿ�������==
                        exist = 1;
                        break;
                    }
                }
                if (!exist)
                    res.push_back(ent);
            }   // ��Ч��
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