class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        if (m*n != size) return {};
        vector<vector<int>> ans;
        vector<int> temp;
        for (int i=0; i<size; i++){
            temp.push_back(original[i]);
            if ((i+1)%n == 0){
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};