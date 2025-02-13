class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;  // 改成由小排到大。
        for (int num: nums){
            pq.push(num);
        }
        int ans = 0;
        long long x = 0;
        long long y = 0;
        while (pq.top() < k){
            ans++;
            x = pq.top();
            pq.pop();
            y = pq.top();
            pq.pop();
            pq.push(2*x+y);
        }
        return ans;
    }
};

// Reference from 【筆記】常用C++ STL：priority_queue, https://yuihuang.com/cpp-stl-priority-queue/.