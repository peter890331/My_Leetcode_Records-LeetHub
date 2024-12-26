int findTargetSumWays(int* nums, int numsSize, int target) {    // 有給 nums.size() !
    // 假設使用 + 號的子集的總和為 P ，使用 - 號的子集的總和為 N 。
    // P − N = target
    // P + N = sum
    // => (P−N) + (P+N) = target + sum
    // => P = (target + sum) / 2
    // 只要找到總和為 P 的子集即可。

    int sum = 0;
    for (int i=0; i<numsSize; i++){
        sum += nums[i];
    }
    int P = (target + sum) / 2;

    if (P<0 || (target + sum)%2!=0) return 0;  // 如果 P 為負數 或 如果 (target + sum) / 2 無法整除，找不到子集。

    int* dp = (int*)calloc(P + 1, sizeof(int));  // 建立 dp ，表示總和為某數的子集數量。
    dp[0] = 1;  // 總合為 0 的子集數量為 1 ，就是空集合。

    for (int i=0; i<numsSize; i++){    // 正向迭代 nums 中的數字。
        for (int temp=P; temp>=0; temp--){  // 反向迭代 P~0 ，避免錯誤累加。
            if (temp>=nums[i]){
                dp[temp] += dp[temp-nums[i]];
            }
        }
    }
    return dp[P];   // 返回總和為 P 的子集數量。

    /*
    int result = dp[P]; // 獲取結果
    free(dp);           // 釋放記憶體
    return result;
    */
}

// Reference from An-Wen Deng's solution.

/*
關於 malloc 和 calloc。

初始化記憶體：
malloc：只是分配記憶體，但內容是隨機數據。
calloc：分配記憶體後，所有數組元素都會初始化為零。

語法：
malloc：void* ptr = malloc(size);
calloc：void* ptr = calloc(num_elements, element_size);

用途：
malloc 常用於分配大小未知的記憶體，且需要自行初始化數據。
calloc 用於分配大規模連續的記憶體區塊，並自動初始化為零。
*/