class Solution {
public:
    string reverseVowels(string s) {
        string s_ = s;
        int n = s_.size();
        int left = 0;
        int right = n-1;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while (left < right){
            while (left < n && vowels.find(s_[left]) == vowels.end()){
                left++;
            }
            while (right > 0 && vowels.find(s_[right]) == vowels.end()){
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