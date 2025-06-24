class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        set<int> ans_set;
        for (int i=0; i<n; i++) {
            if (nums[i] == key) {
                int l = max(0, i-k);
                int r = min(i+k, n-1);
                for (int j=l; j<=r; j++) {
                    ans_set.insert(j); 
                }
            }
        }
        vector<int> ans_vector(ans_set.begin(), ans_set.end());
        return ans_vector;
    }
};