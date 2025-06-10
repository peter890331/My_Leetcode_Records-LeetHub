class Solution {
public:
    int maxDifference(string s) {
        vector<int> count(26, 0);
        for (char ch: s) {
            count[ch - 'a']++;
        }
        int odd = 0;
        int even = 101;
        for (int i=0; i<26; i++) {
            if (count[i] % 2 == 1) {
                odd = max(odd, count[i]);
            }
            if (count[i] % 2 == 0 && count[i] > 0) {
                even = min(even, count[i]);
            }
        }
        return odd - even;
    }
};