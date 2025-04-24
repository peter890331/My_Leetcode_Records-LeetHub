class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> total_count;
        for (int i=0; i<n; i++){
            total_count.insert(nums[i]);
        }
        int total_elements = total_count.size();
        unordered_map<int, int> window_count;
        int left = 0; int window_elements = 0; int ans = 0;
        for (int right=0; right<n; right++){
            if (++window_count[nums[right]] == 1){
                window_elements++;
            }
            while (window_elements == total_elements){
                ans += n - right;
                if (--window_count[nums[left]] == 0){
                    window_elements--;
                }
                left++;
            }
        }
        return ans;
    }
};