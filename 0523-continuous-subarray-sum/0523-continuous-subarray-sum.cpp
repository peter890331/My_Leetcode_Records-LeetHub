// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         if (n<2)
//             return false;

//         vector<int> prefix(n+1, 0);
//         for (int i=0; i<n; i++){
//             prefix[i+1] = prefix[i] + nums[i];
//         }
//         print(prefix);

//         for (int i=0; i<=n-2; i++){
//             for (int j=i+2; j<=n; j++){
//                 int res = prefix[j] - prefix[i];
//                 if (res % k == 0){
//                     cout<<res;
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }

// private:
//     void print(vector<int> prefix){
//         for (int i=0; i<prefix.size(); i++){
//             cout<<prefix[i]<<',';
//         }
//         cout<<endl;
//     }
// };

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> remainderMap;
        int cumulativeSum = 0;
        
        // Step 1: Initialize Remainder Map
        remainderMap[0] = -1;
        
        // Step 2: Iterate Through the List
        for (int i = 0; i < n; i++) {
            // Step 3: Calculate Cumulative Sum
            cumulativeSum += nums[i];
            
            // Step 4: Calculate Remainder
            int remainder = k == 0 ? cumulativeSum : cumulativeSum % k;
            
            // Step 5: Update Remainder Map
            if (remainderMap.count(remainder)) {
                // Check if segment length is at least two
                if (i - remainderMap[remainder] > 1) {
                    return true;
                }
            } else {
                remainderMap[remainder] = i;
            }
        }
        
        // Step 6: Return the Result
        return false;
    }
};

// Prefix.
// Mohammed_Raziullah_Ansari's solution.