class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> friends;
        for (int i=1; i<=n; i++){
            friends.push_back(i);
        }
        int from_friend = 0;
        while(friends.size() > 1){
            int remove = (from_friend+k-1)%friends.size();
            friends.erase(friends.begin()+remove);
            from_friend = remove;
        }
        return friends[0];
    }
};