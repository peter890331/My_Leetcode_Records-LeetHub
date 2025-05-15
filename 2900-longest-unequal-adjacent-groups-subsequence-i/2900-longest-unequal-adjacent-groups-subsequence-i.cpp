class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int temp = -1;
        for (int i=0; i<groups.size(); i++){
            if (groups[i] != temp){
                ans.push_back(words[i]);
                temp = groups[i];
            }
        }
        return ans;
    }
};