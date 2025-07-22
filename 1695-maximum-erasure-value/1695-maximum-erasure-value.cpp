class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> count;
        int left = 0;
        int n = nums.size();
        int temp = 0;
        int ans = 0;
        for (int right=0; right<n; right++) {
            count[nums[right]]++;
            temp += nums[right];
            while (count[nums[right]] > 1) {
                count[nums[left]]--;
                temp -= nums[left];
                left++;
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};

// Reference from 1695. Maximum Erasure Value - Day 22/31 Leetcode July Challenge, https://youtu.be/h4JeUGTDsGM.