class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        for (int i=1; i<n; i++){
            if (ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }

        for (int j=n-2; j>=0; j--){
            if (ratings[j] > ratings[j+1]){
                candies[j] = max(candies[j+1] + 1, candies[j]);
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

// Reference from 贪心算法，两者兼顾很容易顾此失彼！LeetCode：135.分发糖果 | 135. Candy, https://youtu.be/H-FQOYdeSEM.