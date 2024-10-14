class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        long long ans = 0;
        for (int i=0; i<n; i++){
            pq.push(nums[i]);
        }
        for (int j=0; j<k; j++){
            float largest = pq.top();
            ans += largest;
            pq.pop();
            pq.push(ceil(largest/3));
        }
        return ans;
    }
};