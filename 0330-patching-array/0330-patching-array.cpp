class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1; // 初始化最小無法表示的數字為1
        int result = 0;     // 需要補充的數字個數
        size_t i = 0;       // 數組nums的索引
        // size_t 是一種無符號整數類型，這意味著它只能表示非負數。

        // 當miss小於等於n時，繼續循環
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                // 如果nums[i]能幫助表示當前的miss，則更新miss
                miss += nums[i];
                i++; // 移動到下一個數字
            } else {
                // 否則，插入miss來擴展範圍，並更新miss
                miss += miss;
                result++; // 增加補充數字的計數
            }
        }

        return result; // 返回需要補充的數字個數
    }
};

// Greedy Approach
// bhanu_bhakta's solution.