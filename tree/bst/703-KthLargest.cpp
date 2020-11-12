/*
 * @Description: 数据流中的第K大元素
 * @Author: guchen
 * @Date: 2020-11-12 20:18:59
 * @LastEditTime: 2020-11-12 20:19:21
 */
#include "../alg.h"

class KthLargest {
public:
    multiset<int> s;
    int K;
    // 只在multiset中保留最大的K个数
    KthLargest(int k, vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
            if (s.size() > k) s.erase(s.begin());
        }
        K = k;
    }
    
    int add(int val) {
        s.insert(val);
        if (s.size() > K) s.erase(s.begin());
        return *s.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
