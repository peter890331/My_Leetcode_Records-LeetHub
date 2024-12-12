class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        priority_queue<int> sorted_gifts;
        int max_gift = 0;
        long long ans = 0;

        for (int gift: gifts){
            sorted_gifts.push(gift);
        }

        for (int i=0; i<k; i++){
            max_gift = sorted_gifts.top();
            sorted_gifts.pop();
            sorted_gifts.push(sqrt(max_gift));
        }

        while (!sorted_gifts.empty()){
            ans += sorted_gifts.top();
            sorted_gifts.pop();
        }

        return ans;
    }
};