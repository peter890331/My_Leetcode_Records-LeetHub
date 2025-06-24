class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> key_index;
        vector<int> ans_index;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == key) {
                key_index.push_back(i);
            }
        }
        for (int i=0; i<nums.size(); i++) {
            for (int j=0; j<key_index.size(); j++) {
                if (abs(i-key_index[j]) <= k) {
                    ans_index.push_back(i);
                    break;
                }
            }
        }
        return ans_index;
    }
};