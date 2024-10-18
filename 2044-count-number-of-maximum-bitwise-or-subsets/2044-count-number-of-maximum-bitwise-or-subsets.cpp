class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int max = 0;
        int ans = 0;
        for (int i=1; i<(1<<n); i++){
            int temp = 0;
            for (int j=0; j<n; j++){
                if (i & (1<<j)){
                    temp |= nums[j];
                }
            }
            if (temp > max){
                max = temp;
                ans = 1;
            }
            else if (temp == max){
                ans++;
            }
        }
        return ans;
    }
};

// Reference from LeetCode - 2044. Count Number of Maximum Bitwise-OR Subsets　解題心得, https://home.gamer.com.tw/artwork.php?sn=5426853.