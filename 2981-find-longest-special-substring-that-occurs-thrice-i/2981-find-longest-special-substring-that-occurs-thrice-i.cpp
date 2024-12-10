class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int l = 1, r = n;

        if (!helper(s, n, l)) return -1;

        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (helper(s, n, mid)) l = mid;
            else r = mid;
        }

        return l;
    }

private:
    bool helper(const string& s, int n, int x) {
        vector<int> cnt(26, 0);
        int p = 0;

        for (int i = 0; i < n; i++) {
            while (s[p] != s[i]) p++;
            if (i - p + 1 >= x) cnt[s[i] - 'a']++;
            if (cnt[s[i] - 'a'] > 2) return true;
        }

        return false;
    }
};

// Sumeet Sharma's solution.
// binary search 找最大長度，sliding window 驗證最大長度是否合理。

/*

helper("aaabaaabaaa", 11, 3)
s = "aaabaaabaaa", n = 11, x = 3

遍歷過程：
i	s[i]	p	當前子串 [p, i]	長度 i - p + 1	cnt 狀態	是否滿足條件
0	a	0	a	    1	    cnt[0] = 0	No
1	a	0	aa	    2	    cnt[0] = 0	No
2	a	0	aaa	    3	    cnt[0] = 1	No
3	b	3	b	    1	    cnt[1] = 0	No
4	a	4	a	    1	    cnt[0] = 1	No
5	a	4	aa	    2	    cnt[0] = 1	No
6	a	4	aaa	    3	    cnt[0] = 2	No
7	b	7	b	    1	    cnt[1] = 0	No
8	a	8	a	    1	    cnt[0] = 2	No
9	a	8	aa	    2	    cnt[0] = 2	No
10	a	8	aaa	    3	    cnt[0] = 3	Yes

結果：true，因為 aaa 至少出現了三次。

*/