class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxValue = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == maxValue){
                ans++;
            }
        } 
        return ans;
    }
};