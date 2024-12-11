class Solution {
public:
    int maximumBeauty(vector<int>& A, int k) {

        sort(A.begin(), A.end());

        // for (int a: A)
        //     cout<<a<<',';
        // cout<<endl;

        int i = 0, j, n = A.size();
        for (j = 0; j < n; ++j){
            if (A[j] - A[i] > k * 2)
                i++;
            // cout<<i<<','<<j<<endl;
        }

        return j - i;

    }
};

// JK_01's solution.