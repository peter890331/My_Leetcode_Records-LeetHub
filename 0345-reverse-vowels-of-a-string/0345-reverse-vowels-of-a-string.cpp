class Solution {
public:
    string reverseVowels(string s) {
        string s_ = s;
        int n = s_.size();
        int left = 0;
        int right = n-1;
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while (left < right){
            while (left <= n && count(vowels.begin(), vowels.end(), s_[left]) == 0){
                left++;
            }
            while (right >= 0 && count(vowels.begin(), vowels.end(), s_[right]) == 0){
                right--;
            }
            if (left < right){
                swap(s_[left], s_[right]);
                left++;
                right--;
            }
        }
        return s_;
    }
};