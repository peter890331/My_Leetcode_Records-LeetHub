class Solution {
public:
    int numTilings(int n) {
        const int mod = 1e9 + 7;
        if (n == 1) return 1;
        if (n == 2) return 2;
        vector<long long> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        long long sum = dp[0];
        for (int i=3; i<=n; i++){
            dp[i] = (dp[i-1] + dp[i-2] + 2 * sum) % mod;
            sum += dp[i-2];
        }
        return dp[n] % mod;
    }
};

// dp[i] = dp[i-1] + dp[i-2] + 2 * (dp[0] + dp[1] + ... + dp[i-3]) = dp[i-1] + dp[i-2] + 2 * sum