class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 假設使用 + 號的子集的總和為 P ，使用 - 號的子集的總和為 N 。
        // P − N = target
        // P + N = sum
        // => (P−N) + (P+N) = target + sum
        // => P = (target + sum) / 2
        // 只要找到總和為 P 的子集即可。

        int n = nums.size();
        int sum = 0;
        for (int i=0; i<n; i++){
            sum += nums[i];
        }
        // int sum=accumulate(nums.begin(), nums.end(), 0);
        int P = (target + sum) / 2;

        if (P<0 || (target + sum)%2!=0) return 0;  // 如果 P 為負數 或 如果 (target + sum) / 2 無法整除，找不到子集。

        vector<int> dp(P+1, 0);  // 建立 dp ，表示總和為某數的子集數量。
        dp[0] = 1;  // 總合為 0 的子集數量為 1 ，就是空集合。

        for (int num: nums){    // 正向迭代 nums 中的數字。
            for (int temp=P; temp>=0; temp--){  // 反向迭代 P~0 ，避免錯誤累加。
                if (temp>=num){
                    dp[temp] += dp[temp-num];
                }
            }
        }
        return dp[P];   // 返回總和為 P 的子集數量。
    }
};