class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int real_count = 0;
        int test_count = 0;
        for (int i=0; i<n; i++){
            real_count += i;
            test_count += arr[i];
            if (real_count == test_count){
                ans++;
                real_count = 0;
                test_count = 0;
            }
        }
        return ans;
    }
};