class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> count;
        vector<int> ans;
        vector<int> remaining;
        int n1 = arr1.size();
        int n2 = arr2.size();

        for (int i=0; i<n1; i++) {
            count[arr1[i]]++;
        }

        for (int i=0; i<n2; i++) {
            int temp = arr2[i];
            while (count[temp] > 0) {
                ans.push_back(temp);
                count[temp]--;
            }
            count.erase(temp);
        }

        for (auto it: count) {
            while (it.second > 0) {
                remaining.push_back(it.first);
                it.second--;
            }
        }

        sort(remaining.begin(), remaining.end());

        for (int i=0; i<remaining.size(); i++) {
            ans.push_back(remaining[i]);
        }

        return ans;
    }
};