class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();                            // 取得nums的大小

        vector<int> diff(n+1, 0);                       // 差分數組，用來記錄翻轉次數的增量
        int flips = 0;                                  // 當前翻轉次數

        int ans = 0;                                    // 最少的翻轉次數

        for (int i=0; i<n; i++){

            flips += diff[i];                           // 更新當前位置的翻轉次數
            if ((nums[i]+flips) % 2 == 1) continue;     // 如果當前元素加上當前位置的翻轉次數後是1，則不需要翻轉

            // 如果當前元素加上當前位置的翻轉次數後是0，則需要翻轉
            if (i+k-1 >= n)  return -1;                 // 如果無法再進行一次翻轉（會超出nums的大小），返回-1
            flips++;                                    // 增加當前翻轉次數
            ans++;                                      // 記錄一次翻轉次數
            diff[i+k] -= 1;                             // 在i+k位置減少翻轉次數，表示i+k之後翻轉影響結束
        }

        return ans;
    }
};

// Reference from 【每日一题】995. Minimum Number of K Consecutive Bit Flips, 5/26/2021, https://youtu.be/c5o-x_kD8d8.