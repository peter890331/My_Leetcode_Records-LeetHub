class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        bool test0 = 0, test1 = 1, last0 = 0, last1 = 1;    // if original[0] = 0 and if original[0] = 1.
        for (int i=0; i<n-1; i++){
            last0 ^= derived[i];    // calculate original[n-1] if original[0] = 0.
            last1 ^= derived[i];    // calculate original[n-1] if original[0] = 1.
        }
        if (test0 ^ last0 == derived[n-1] || test1 ^ last1 == derived[n-1]) // if (original[0] ^ original[n-1] == derived[n-1]).
            return true;
        else
            return false;
    }
};

// Reference from LeetCode - 2683. Neighboring Bitwise XOR　解題心得, https://home.gamer.com.tw/artwork.php?sn=5970680.