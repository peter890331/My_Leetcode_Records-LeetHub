class Solution {
public:
    int maximumSwap(int num) {
        string num_ = to_string(num);
        int n = num_.size();
        vector<int> last(10, -1);

        for (int i=0; i<n; i++){
            last[num_[i] - '0'] = i;
        }

        for (int i=0; i<n; i++){
            for (int j=9; j>(num_[i] - '0'); j--){
                if (last[j] > i){
                    swap(num_[i], num_[last[j]]);
                    return stoi(num_);
                }
            }
        }
        return num;
    }
};