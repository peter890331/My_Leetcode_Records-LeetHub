class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        while (s.size() % k != 0) {
            s += fill;
        }
        vector<string> ans;
        for (int i=0; i<s.size(); i+=k) {
            string temp = "";
            for (int j=0; j<k; j++) {
                temp += s[i+j];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};