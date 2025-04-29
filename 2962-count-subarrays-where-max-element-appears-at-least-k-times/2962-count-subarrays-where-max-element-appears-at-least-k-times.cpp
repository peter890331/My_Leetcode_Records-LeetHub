class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        long long ans = 0;
        int left = 0;
        for (int right=0; right<n; right++){
            if (nums[right] == max){
                count++;
            }
            while (count == k){
                ans += n - right;
                if (nums[left] == max){
                    count--;
                }
                left++;
            }
        }
        return ans;
    }
};