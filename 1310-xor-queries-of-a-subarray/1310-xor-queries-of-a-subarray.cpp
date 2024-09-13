class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int arr_size = arr.size();
        int queries_size = queries.size();
        vector<int> prefix(arr_size + 1, 0);
        vector<int> ans(queries_size, 0);

        for (int i=0; i<arr_size; i++){
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        for (int i: prefix) cout << i << ',';

        for (int i=0; i<queries_size; i++){
            ans[i] = prefix[queries[i][1]+1] ^ prefix[queries[i][0]];
        }

        return ans;

    }
};