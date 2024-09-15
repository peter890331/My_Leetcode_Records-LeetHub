class Solution {
public:
    int findTheLongestSubstring(string s) {
        // 初始化一个大小为 32 的数组，用来记录不同 mask 值第一次出现的位置。
        // 因为有 5 个母音字母（a, e, i, o, u），可以用 5 位二进制数来表示它们的出现次数的奇偶性（偶数为 0，奇数为 1），
        // 所以最多会有 2^5 = 32 种不同的状态（即 32 种不同的 mask 值）。
        // 初始值都为 -2，表示还未出现该 mask。
        vector<int> mapy(32, -2);
        mapy[0] = -1;   // 初始状态下 mask 为 0，记录位置为 -1（因为还没开始遍历）。

        int maxLen = 0; // 记录符合条件的最长子字符串的长度。
        int mask = 0;   // 用于记录当前母音字母的奇偶性状态。

        // 开始遍历字符串。
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];         // 当前遍历的字符。

            // 通过异或操作更新 mask 的对应位，记录母音的奇偶性。
            switch (ch) {
                case 'a':
                    mask ^= 1;  // 'a' 对应 mask 的第 1 位。
                    break;
                case 'e':
                    mask ^= 2;
                    break;
                case 'i':
                    mask ^= 4;
                    break;
                case 'o':
                    mask ^= 8;
                    break;
                case 'u':
                    mask ^= 16;
                    break;
            }

            // 检查当前 mask 是否已经出现过。
            int prev = mapy[mask];
            if (prev == -2) {
                // 如果当前 mask 第一次出现，记录当前的位置 i。
                mapy[mask] = i;
            } else {
                // 如果当前 mask 之前出现过，计算从上一次出现这个 mask 到当前的子字符串长度。
                // 因为相同的 mask 意味着这段子字符串中的所有元音字母的出现次数是偶数。
                maxLen = max(maxLen, i - prev);
            }
        }

        return maxLen;         // 返回符合条件的最长子字符串的长度。
    }
};

// hemanth00405's solution.