/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    ans[0] = nums[0];
    for (int i=1; i<numsSize; i++){
        ans[i] = nums[i] + ans[i-1];
    }
    return ans;
}