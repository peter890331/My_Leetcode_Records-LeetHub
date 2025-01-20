class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> mat_map;
        int m = mat.size();
        int n = mat[0].size();
        vector<long> row_sum(m, 0);
        vector<long> col_sum(n, 0);
        int a = arr.size();

        for (int row=0; row<m; row++){
            for (int col=0; col<n; col++){
                row_sum[row] += mat[row][col];
                col_sum[col] += mat[row][col];
                mat_map[mat[row][col]] = {row, col};
            }
        }

        for (int index=0; index<a; index++){
            int val = arr[index];
            row_sum[mat_map[val].first] -= val;
            if (row_sum[mat_map[val].first] == 0) return index;
            col_sum[mat_map[val].second] -= val;
            if (col_sum[mat_map[val].second] == 0) return index;
        }

        return -1;

    }
};

// Reference from Sumeet Sharma's solution.