class Solution {
public:
    int countTriplets(std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> prefix(n + 1, 0);

        // 計算前綴異或和
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }

        // 計算滿足條件的三元組
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int k = i + 1; k < n; ++k) {
                if (prefix[i] == prefix[k + 1]) {   // 確認從 i 到 k 的區間內異或和為零，prefix[i] ^ prefix[k + 1] == 0?
                    cout << prefix[i] << '^' << prefix[k+1] << '=' << (prefix[i] ^ prefix[k+1]) << endl;
                    count += (k - i);
                }
            }
        }

        return count;
    }
};

// Prefix.
// XXXX [iXXXXX] [jXXk] XX
// prefix[i+1] = arr[0] ^ arr[1] ^ ... ^ arr[i]

// arr[i] ^ arr[i+1] ^ ... arr[k] = 0
// 確認從 i 到 k 的區間內異或和為零，這意味著在這個區間內找到的所有 j (其中 i < j <= k) 都可以構成一個滿足條件的三元組。
// arr[i] ^ arr[i+1] ^ ... ^ arr[j-1] = prefix[j]   ^ prefix[i]
// arr[j] ^ arr[j+1] ^ ... ^ arr[k]   = prefix[k+1] ^ prefix[j]
// 如果 prefix[i] == prefix[k+1]
// prefix[j]   ^ prefix[i] == prefix[j]   ^ prefix[k+1] == prefix[j] ^ prefix[i]
// prefix[k+1] ^ prefix[j] == prefix[k+1] ^ prefix[j]   == prefix[i] ^ prefix[j]
// 所以 i~k 中的每個 j 都能劃分為兩個相等的異或部分。

// MrAke's solution.