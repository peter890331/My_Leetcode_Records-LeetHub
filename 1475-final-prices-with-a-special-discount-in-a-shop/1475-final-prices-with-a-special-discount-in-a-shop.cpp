class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        int j = 0;
        for (int i=0; i<n; i++){
            j = i + 1;
            while (j < n){
                if (prices[j] <= prices[i]){
                    prices[i] = prices[i] - prices[j];
                    break;
                }
                j++;
            }
        }
        return prices;
    }
};