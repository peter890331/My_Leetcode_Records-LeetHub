class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min_ = nums[0];
        int ans = 0;
        int n = nums.size();
        for (int i=1; i<n; i++) {
            if (nums[i] > min_) {
                ans = max(ans, nums[i] - min_);
            }
            min_ = min(min_, nums[i]);
        }
        return (ans == 0)? -1: ans;;
    }
};