class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int temp = nums[0];
        int max_ = 0;
        for (int i=1; i<n; i++){
            if (nums[i-1] < nums[i]){
                temp += nums[i];
            }
            else {
                max_ = max(max_, temp);
                temp = nums[i];
            }
        }
        max_ = max(max_, temp);
        return max_;
    }
};