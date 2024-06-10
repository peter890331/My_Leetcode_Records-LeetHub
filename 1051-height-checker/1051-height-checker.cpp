class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> sorted_heights = heights;
        sort(sorted_heights.begin(), sorted_heights.end());
        int ans = 0;
        for (int i=0; i<n; i++){
            if (heights[i]!=sorted_heights[i])
                ans++;
        }
        return ans;
    }
};