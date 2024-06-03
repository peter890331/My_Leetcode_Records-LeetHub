class Solution {
public:
    int appendCharacters(string s, string t) {
        int s_ = s.size();
        int t_ = t.size();
        int i = 0;
        int j = 0;
        while(i < s_){
            if (j < t_ & s[i] == t[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return t_ - j;
    }
};