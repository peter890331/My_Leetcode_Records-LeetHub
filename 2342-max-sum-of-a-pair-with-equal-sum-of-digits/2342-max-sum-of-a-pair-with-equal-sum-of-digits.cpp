class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        int sum = 0;
        int temp = 0;
        vector<int> sum_(82, 0);
        for (int num: nums){
            sum = 0;
            temp = num;
            while (temp){
                sum += temp % 10;
                temp /= 10;
            }
            if (sum_[sum]){
                ans = max(ans, num + sum_[sum]);
            }
            sum_[sum] = max(sum_[sum], num);
        }
        return ans;
    }
};