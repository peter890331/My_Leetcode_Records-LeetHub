class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        while (s.size() % k != 0) {
            s += fill;
        }
        vector<string> ans;
        for (int i=0; i<s.size(); i+=k) {
            string temp = "";
            ans.push_back(s.substr(i, k));
        }
        return ans;
    }
};