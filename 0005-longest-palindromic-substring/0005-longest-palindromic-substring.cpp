class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        for (int i=0; i<n; i++){
            for (int j=n-1; j>0; j--){
                if (i<j && check(s, i, j) && (j-i>right-left)){
                    left = i;
                    right = j;
                }
            }
        }
        return s.substr(left, right-left+1);
    }
private:
    bool check(const string& s, int left, int right){
        while (left < right){
            if (s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};