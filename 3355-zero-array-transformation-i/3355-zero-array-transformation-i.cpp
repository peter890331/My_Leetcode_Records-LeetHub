class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n+1, 0);
        for(auto querie: queries){
            diff[querie[0]]--;
            diff[querie[1]+1]++;
        }
        int temp = 0;
        for (int i=0; i<n; i++){
            temp += diff[i];
            if (nums[i] + temp > 0){
                return false;
            }
        }
        return true;
    }
};