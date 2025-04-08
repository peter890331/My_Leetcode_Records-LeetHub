class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> count;
        vector<int> nums_temp = nums;
        int n = nums_temp.size();
        int ans = 0;
        for (int num: nums_temp){
            count[num]++;
        }
        if (n == count.size()){
            return 0;
        }
        while (n >= 3){
            ans++;
            for (int i=0; i<3; i++){
                count[nums_temp[i]]--;
                if (count[nums_temp[i]] == 0){
                    count.erase(nums_temp[i]);
                }
            }
            nums_temp.erase(nums_temp.begin(), nums_temp.begin()+3);
            n = nums_temp.size();
            if (n == count.size()){
                return ans;  
            }
        }
        return (n == count.size())? ans: ans+1;
    }
};