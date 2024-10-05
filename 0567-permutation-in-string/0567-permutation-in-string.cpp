class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1_n = s1.size();
        int s2_n = s2.size();
        
        if (s1_n > s2_n) return false;

        unordered_map<char, int> s1_map;
        unordered_map<char, int> s2_map;

        for (char c : s1) {
            s1_map[c]++;
        }
        for (int i = 0; i < s1_n; i++) {
            s2_map[s2[i]]++;
        }

        if (s1_map == s2_map) return true;

        for (int i = s1_n; i < s2_n; i++) {
            s2_map[s2[i]]++;
            s2_map[s2[i - s1_n]]--;
            if (s2_map[s2[i - s1_n]] == 0) {
                s2_map.erase(s2[i - s1_n]);
            }
            if (s1_map == s2_map) return true;
        }

        return false;

    }
};

// sliding window.