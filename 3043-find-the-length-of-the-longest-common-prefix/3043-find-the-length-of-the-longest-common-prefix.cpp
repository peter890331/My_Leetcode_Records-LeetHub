class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefix_set;

        for (int arr1_: arr1){
            string prefix_temp = "";
            string arr1__ = to_string(arr1_);
            for (char ch: arr1__){
                prefix_temp += ch;
                prefix_set.insert(prefix_temp);
            }
        }

        int ans = 0;
        int prefix_temp_size = 0;
        for (int arr2_: arr2){
            string prefix_temp = "";
            string arr2__ = to_string(arr2_);
            for (char ch: arr2__){
                prefix_temp += ch;
                if (prefix_set.find(prefix_temp) != prefix_set.end()){
                    prefix_temp_size = prefix_temp.size();
                    ans = max(ans, prefix_temp_size);
                    // ans = max(ans, static_cast<int>(prefix_temp.size()));
                }
            }
        }

        return ans;

    }
};

// Reference from withaarzoo's solution.