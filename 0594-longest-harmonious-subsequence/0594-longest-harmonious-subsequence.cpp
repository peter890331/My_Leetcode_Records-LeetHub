class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> map;
        for (int num: nums) {
            map[num]++;
        }
        int ans = 0;
        for (auto [num, times]: map){
            if (map.count(num+1)) {
                ans = max(ans, times + map[num+1]);
            }
        }
        return ans;
    }
};