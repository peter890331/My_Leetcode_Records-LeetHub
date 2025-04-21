class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        vector<long> prefix_sum(n+1, 0);
        prefix_sum[0] = 0;
        for (int i=0; i<n; i++){
            prefix_sum[i+1] = prefix_sum[i] + differences[i];
        }
        long long min_prefix = *min_element(prefix_sum.begin(), prefix_sum.end());
        long long max_prefix = *max_element(prefix_sum.begin(), prefix_sum.end());
        long long left = lower - min_prefix;
        long long right = upper - max_prefix;
        return (left > right)? 0: right - left + 1;
    }
};