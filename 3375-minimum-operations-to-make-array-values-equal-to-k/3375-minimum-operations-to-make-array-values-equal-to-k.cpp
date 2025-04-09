class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s;
        bool equal = true;
        for (int num: nums){
            if (num > k){
                s.insert(num);
                equal = false;
            }
            else if (num < k){
                return -1;
            }
        }
        return equal? 0: s.size();
    }
};