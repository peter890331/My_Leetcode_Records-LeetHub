class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n, 0);
        for(auto querie: queries){
            for (int i=querie[0]; i<=querie[1]; i++){
                diff[i]--;
            }
        }
        for (int i=0; i<n; i++){
            if (nums[i] + diff[i] > 0){
                return false;
            }
        }
        return true;
    }
};