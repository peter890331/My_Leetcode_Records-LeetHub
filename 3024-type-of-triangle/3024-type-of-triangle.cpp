class Solution {
public:
    string triangleType(vector<int>& nums) {
        unordered_set<int> count;
        for (int num: nums){
            count.insert(num);
        }
        if (count.size() == 1){
            return "equilateral";
        }
        else {
            if (nums[0]+nums[1]>nums[2] && nums[0]+nums[2]>nums[1] && nums[1]+nums[2]>nums[0]){
                if (count.size() == 2){
                    return "isosceles";
                }
                else return "scalene";
            }
        }
        return "none";
    }
};