class Solution {
public:
    int possibleStringCount(string word) {
        vector<int> count;
        char temp_word = word[0];
        int temp_count = 1;
        for (int i=1; i<word.size(); i++) {
            if (word[i] != temp_word) {
                count.push_back(temp_count);
                temp_count = 1;
                temp_word = word[i];
            }
            else {
                temp_count++;
            }
        }
        count.push_back(temp_count);
        int ans = 0;
        for (int c: count) {
            if (c > 1) {
                ans += c-1;
            }
        }
        return (ans==0)? 1: ans+1;
    }
};