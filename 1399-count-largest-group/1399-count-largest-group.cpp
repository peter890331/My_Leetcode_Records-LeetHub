class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> count(37, 0);
        for (int i=1; i<=n; i++){
            int sum = 0;
            int temp = i;
            while (temp > 0){
                sum += temp % 10;
                temp /= 10;
            }
            count[sum]++;
        }
        int largest_size = *max_element(count.begin(), count.end());
        int ans = 0;
        for (int size: count){
            if (size == largest_size){
                ans++;
            }
        }
        return ans;
    }
};