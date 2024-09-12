class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, bool> allowed_map;
        int ans = 0;

        for (char allowed_char: allowed){
            allowed_map[allowed_char] = true;
        }

        for (string word: words){
            bool flag = true;
            for (char word_char: word){
                if (allowed_map[word_char] != true){
                    flag = false;
                    break;
                }
            }
            if (flag) ans++;
        }

        return ans;

    }
};