class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> alphabet(26, 0);
        for (char tile: tiles){
            alphabet[tile - 'A']++;
        }
        return dfs(alphabet);
    }
private:
    int dfs(vector<int>& alphabet){
        int ans = 0;
        for (int i=0; i<alphabet.size(); i++){
            if (alphabet[i] == 0){
                continue;
            }
            ans++;
            alphabet[i]--;
            ans += dfs(alphabet);   // recursive.
            alphabet[i]++;          // backtrace.
        }
        return ans;
    }
};

// Reference from 猩猩的乐园 Leetcode 1079 Letter Tile Possibilities, https://youtu.be/My9FkIGAPos.