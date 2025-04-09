class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s;
        int equal = 1;
        for (int num: nums){
            if (num > k){
                s.insert(num);
                equal = 0;
            }
            else if (num < k){
                return -1;
            }
        }
        return (equal == 1)? 0: s.size();
    }
};