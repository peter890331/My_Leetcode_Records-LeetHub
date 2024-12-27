class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        int Prev = values[0];   // value[0] + 0

        for (int j = 1; j < values.size(); j++) {
            ans = max(ans, Prev + values[j] - j);   // calculate (value[i] + i) + (value[j] - j)
            Prev = max(Prev, values[j] + j);    // update value[i] + i
        }

        return ans;
    }
};

// Bijoy Sing's solution.
// Yen Huynh's solution.