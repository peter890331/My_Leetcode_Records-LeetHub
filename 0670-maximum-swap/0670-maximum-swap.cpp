class Solution {
public:
    int maximumSwap(int num) {
        int ans = num;
        string ans_ = "";
        string num_ = to_string(num);
        for (int i=num_.size()-1; i>0; i--){
            ans_ = num_;
            ans_ = num_[i] + ans_;
            ans_.erase(i+1,1);
            ans = max(ans, stoi(ans_));
        }
        return ans;
    }
};