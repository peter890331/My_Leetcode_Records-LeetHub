class Solution {
public:
    long long calc(int x) {  // comb(x, 2)
        if (x < 0) return 0;
        return 1LL * x * (x - 1) / 2;   // 1LL: long long 的常數 1
    }
    long long distributeCandies(int n, int limit) {
        if (n > 3 * limit) return 0;
        long long ans = calc(n+2);                // comb(n+2, 2)
        ans -= 3 * calc(n - limit + 1);
        ans += 3 * calc(n - 2 * limit);
        // ans -= calc(n - 3 * limit - 1);
        return ans; 
    }
};

// Reference from LeetCode \U0001f7e1 2929. Distribute Candies Among Children II, https://gdst.dev/posts/LC-2929/.