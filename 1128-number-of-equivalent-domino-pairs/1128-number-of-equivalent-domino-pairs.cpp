class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> count;
        for (int i=0; i<dominoes.size(); i++){
            int a = dominoes[i][0];
            int b = dominoes[i][1];
            int temp = a < b ? a * 10 + b : b * 10 + a;
            count[temp]++;
        }
        int ans = 0;
        for (auto [temp, freq]: count){
            ans += freq * (freq - 1) / 2;
        }
        return ans;
    }
};

// Reference from Sung Jinwoo's solution.
/*
不能直接使用 unordered_map<pair<int,int>, int> mpp;，原因是：
C++ 的 std::unordered_map 使用雜湊表來儲存 key-value pair，而 pair<int, int> 並沒有內建的 hash function，所以編譯器不知道如何對 pair<int, int> 進行 hashing。

方法 1：自己提供 hash function
    struct hash_pair {
        size_t operator()(const pair<int,int>& p) const {
            return p.first * 31 + p.second;
        }
    };
    unordered_map<pair<int, int>, int, hash_pair> mpp;
    這樣就能讓 unordered_map 使用自定義的 hash 函數來處理 pair。
    
方法 2：改用 map（紅黑樹）而不是 unordered_map
    map<pair<int, int>, int> mpp;
    這是合法的，因為 pair<int,int> 有定義 < 比較運算子（字典序），所以 map 可以排序它，不需要 hash function。但：
    map 是基於平衡二元樹（log n）
    unordered_map 是基於 hash table（平均 O(1)）
    所以使用 unordered_map 的話，效率更高，但需要自己提供 hash 函數。
*/