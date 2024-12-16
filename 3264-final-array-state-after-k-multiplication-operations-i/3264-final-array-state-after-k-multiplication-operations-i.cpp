class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int minPosition = 0;
        for (int i=0; i<k; i++){
            minPosition = min_element(nums.begin(),nums.end()) - nums.begin();
            nums[minPosition] = nums[minPosition] * multiplier;
        }
        return nums;
    }
};