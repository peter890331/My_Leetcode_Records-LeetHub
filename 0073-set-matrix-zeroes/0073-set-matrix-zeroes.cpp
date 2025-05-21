class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_set<int> temp_n;
        unordered_set<int> temp_m;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (matrix[i][j] == 0){
                    temp_n.insert(i);
                    temp_m.insert(j);
                }
            }
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (temp_n.find(i) != temp_n.end() || temp_m.find(j) != temp_m.end()){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};