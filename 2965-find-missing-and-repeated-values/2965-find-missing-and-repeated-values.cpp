class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size() * grid[0].size();
        vector<int> count(n+1, 0);
        int a = -1, b = -1;
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                count[grid[i][j]]++;
            }
        }
        for (int t=1; t<count.size(); t++){
            if (count[t]==2) 
                a = t;
            if (count[t]==0) 
                b = t;
        }
        return {a, b};
    }
};