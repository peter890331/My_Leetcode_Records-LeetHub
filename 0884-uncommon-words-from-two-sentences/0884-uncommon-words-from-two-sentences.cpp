class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        // vector<string> s1and2 = s1 + " " + s2;
        stringstream sentences(s1 + " " + s2);
        string word;
        unordered_map<string, int> words_map;
        vector<string> ans;

        while (sentences >> word){
            words_map[word]++;
        }

        for (auto& pair: words_map){
            if (pair.second == 1){
                ans.push_back(pair.first);
            }
        }

        return ans;

    }
};