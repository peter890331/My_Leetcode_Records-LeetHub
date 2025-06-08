class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n, 0);
        int temp = 1;
        for (int i=0; i<n; i++) {
            ans[i] = temp;
            if (temp * 10 > n) {
                if (temp == n) {
                    temp /= 10;
                }
                temp++;
                while (temp % 10 == 0) {
                    temp /= 10;
                }
            }
            else {
                temp *= 10;
            }
        }
        return ans;
    }
};

// Reference from anwendeng's solution.