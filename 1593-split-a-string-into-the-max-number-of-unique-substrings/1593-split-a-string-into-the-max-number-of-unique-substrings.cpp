class Solution {

    unordered_set<string> substring;
    int ans = 0;

public:
    int maxUniqueSplit(string s) {
        
        // unordered_set<string> substring;
        // string temp = "";
        // int ans = 0;
        // for (char ch: s){
        //     temp += ch;
        //     if (substring.find(temp) == substring.end()){
        //         ans++;
        //         substring.insert(temp);
        //         temp = "";
        //     }
        // }
        // return ans;

        dfs(s, 0, 0);
        return ans;

    }

    void dfs(string &s, int index, int count){
        if (index == s.size()){
            ans = max(ans, count);
            return;
        }

        if (ans >= (count+(s.size()-index))){
            return;
        }

        for (int i=index; i<s.size(); i++){
            if (substring.find(s.substr(index, i-index+1)) == substring.end()){
                substring.insert(s.substr(index, i-index+1));
                dfs(s, i+1, count+1);
                substring.erase(s.substr(index, i-index+1));
            }
        }
    }
};

// dfs.
// Reference from 【每日一题】1593. Split a String Into the Max Number of Unique Substrings, 12/8/2020, https://youtu.be/3BcS3j6pYR4.