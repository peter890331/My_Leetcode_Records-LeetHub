class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<int> row_sum(m, 0);
        vector<int> col_sum(n, 0);
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                row_sum[i] += grid[i][j];
                col_sum[j] += grid[i][j];
            }
        }
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]==1 && (row_sum[i]>1 || col_sum[j]>1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};