class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count = 0;                                      // 最長長度
        long long value = 0;                                // 十進位數值
        long long base = 1;                                 // 二進位權重

        int n = s.length();

        // 從右往左掃（低位優先）
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {                              // 0 一定可以加，對值沒有貢獻
                ++count;
            } 
            else {
                if (base <= k && value + base <= k) {       // 檢查是否加上這個 1 還不會超過 k
                    value += base;
                    ++count;
                }
            }

            // base 乘 2：下一位的權重
            if (base <= k) {
                base *= 2;
            }
        }

        return count;

    }
};