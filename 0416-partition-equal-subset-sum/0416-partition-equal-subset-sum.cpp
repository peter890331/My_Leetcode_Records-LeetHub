class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sums = 0;
        for (int i=0; i<n; i++){
            sums += nums[i];
        }
        if (sums % 2 == 1){
            return false;
        }
        int target = sums / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num: nums){
            for (int i=target; i>=num; i--){
                if (dp[i-num] == true){
                    dp[i] = true;
                }
            }
        }
        return dp[target] == true? true: false;
    }
};