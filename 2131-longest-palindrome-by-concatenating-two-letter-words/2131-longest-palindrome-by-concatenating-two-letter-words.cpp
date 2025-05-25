class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> count;
        for (string word: words){
            count[word]++;
        }
        int ans = 0;
        int middle = false;
        for (string word: words){
            string reverse_word = word;
            reverse(reverse_word.begin(), reverse_word.end());
            if (word != reverse_word){
                if (count[word] > 0 && count[reverse_word] > 0){
                    ans += 4;
                    count[word]--;
                    count[reverse_word]--;
                }
            }
            else {
                if (count[word] == 1){
                    middle = true;
                }
                else {
                    int pair = count[word] / 2;
                    ans += pair * 4;
                    count[word] -= pair * 2;
                }
            }
        }

        if (middle == true){
            ans += 2;
        }

        return ans;

    }
};