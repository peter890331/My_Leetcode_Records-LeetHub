class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i=low; i<high+1; i++){
            string num = to_string(i);
            if (num.size() % 2 != 0){
                continue;
            }
            int half = num.size() / 2;
            int left = 0;
            int right = 0;
            for (int i=0; i<half; i++){
                left += num[i] - '0';
                right += num[i+half] - '0';
            }
            if (left == right){
                ans++;
            }
        }
        return ans;
    }
};