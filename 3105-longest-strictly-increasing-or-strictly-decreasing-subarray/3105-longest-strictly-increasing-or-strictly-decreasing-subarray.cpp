class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int max_in = 0;
        int max_de = 0;
        int temp_in = 1;
        int temp_de = 1;
        int n = nums.size();
        if (n == 1) return 1;
        for (int i=1; i<n; i++){
            if (nums[i] > nums[i-1]){
                temp_in++;
                max_de = max(max_de, temp_de);
                temp_de = 1;
            }
            else if (nums[i] < nums[i-1]){
                temp_de++;
                max_in = max(max_in, temp_in);
                temp_in = 1;
            }
            else {
                temp_in = 1;
                temp_de = 1;
            }
            max_de = max(max_de, temp_de);
            max_in = max(max_in, temp_in);
        }
        return max(max_in, max_de);
    }
};