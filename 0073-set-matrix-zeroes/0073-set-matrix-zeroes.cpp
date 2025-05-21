class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> temp_n;
        vector<int> temp_m;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (matrix[i][j] == 0){
                    temp_n.push_back(i);
                    temp_m.push_back(j);
                }
            }
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (find(temp_n.begin(), temp_n.end(), i) != temp_n.end() || find(temp_m.begin(), temp_m.end(), j) != temp_m.end()){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};