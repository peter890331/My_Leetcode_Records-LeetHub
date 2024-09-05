class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int current_sum = accumulate(rolls.begin(), rolls.end(), 0);    // 计算现有点数总和
        int total_sum = mean * (m + n);                                 // 总点数 = 平均值 × 骰子总数
        int missing_sum = total_sum - current_sum;                      // 需要的总和 = 总点数 - 现有点数

        // 判断需要的总和是否合理
        if (missing_sum < n * 1 || missing_sum > n * 6) {
            return {};              // 无法满足条件
        }

        vector<int> ans(n, 1);      // 初始化答案为全1
        missing_sum -= n * 1;       // 因为已经分配了n个1，剩下的和要分配

        for (int i = 0; i < n && missing_sum > 0; ++i) {
            int add = min(5, missing_sum);                              // 每个骰子最多加5
            ans[i] += add;
            missing_sum -= add;
        }

        return ans;
    }
};
