class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> total_count;
        for (int i=0; i<n; i++){
            total_count.insert(nums[i]);
        }
        int total = total_count.size();
        int ans = 0;
        for (int left=0; left<n; left++){
            unordered_set<int> count;
            for (int right=left; right<n; right++){
                count.insert(nums[right]);
                if (count.size() == total){
                    ans += n - right;
                    break;
                }
            }
        }
        return ans;
    }
};