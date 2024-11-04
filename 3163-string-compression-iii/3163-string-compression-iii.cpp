class Solution {
public:
    string compressedString(string word) {
        char temp = word[0];
        int count = 1;
        string ans = "";

        for (int i=1; i<word.size(); i++){

            if (temp == word[i]){
                if (count<9) count++;
                else{
                    ans += to_string(count);
                    ans += temp;
                    temp = word[i];
                    count = 1;
                }
            }
            else{
                ans += to_string(count);
                ans += temp;
                temp = word[i];
                count = 1;
            }

        }

        ans += to_string(count);
        ans += temp;

        return ans;
    }
};