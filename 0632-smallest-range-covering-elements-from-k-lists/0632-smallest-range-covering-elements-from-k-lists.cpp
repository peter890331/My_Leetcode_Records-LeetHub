class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        set<pair<int, int>> Set;    // {val, numsID}.
        int n = nums.size();
        vector<int> pointers(n);

        // initialize.
        for (int i=0; i<n; i++){
            pointers[i] = 0;
            Set.insert({nums[i][0], i});
        }

        int range = INT_MAX;
        vector<int> ans;

        while (1){
            int new_range = Set.rbegin()->first - Set.begin()->first;

            if (new_range < range){
                range = new_range;
                ans = {Set.begin()->first, Set.rbegin()->first};
            }

            int i = Set.begin()->second;
            pointers[i]++;
            if (pointers[i]==nums[i].size()){
                break;
            }
            Set.erase(Set.begin());
            Set.insert({nums[i][pointers[i]], i});
        }

        return ans;

    }
};

// Reference from 【每日一题】632. Smallest Range Covering Elements from K Lists, 12/3/2020, https://youtu.be/ejVD92bJe34.
// Reference from 反向迭代器（rbegin,rend）, https://blog.csdn.net/kjing/article/details/6936325.