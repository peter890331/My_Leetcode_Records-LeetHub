class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxValue = *max_element(nums.begin(), nums.end());
        int ans = 0;
        int temp = 0;
        
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == maxValue){
                temp++;
            }
            else{
                ans = max(ans, temp);
                temp = 0;
            }
        } 
        return ans = max(ans, temp);
    }
};

// Reference from C++数组或vector求最大值最小值, https://www.cnblogs.com/Tang-tangt/p/9352093.html.