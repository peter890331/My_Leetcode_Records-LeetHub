class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<bool> dp(1501, false);
        dp[0] = true;
        int sum = 0;
        for (int stone: stones){
            sum += stone;
            for (int i=min(1500, sum); i>=stone; i--){
                dp[i] = dp[i] || dp[i - stone];
            }
        }
        for (int i=sum/2; i>=0; i--){
            if (dp[i] == true){
                return sum - 2 * i;
            }
        }
        return 0;
    }
};

// Reference from [LeetCode] 1049. Last Stone Weight II 最后的石头重量之二, https://www.cnblogs.com/grandyang/p/14480433.html.