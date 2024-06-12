void sortColors(int* nums, int numsSize) {
    //Dutch national flag problem (red, white, blue)
    const int red=0, white=1, blue=2;
    int l=0, m=0, r=numsSize-1;// pointers to partition
    int temp;
    while(m<=r){
        switch(nums[m]){
            case red:
                // 將紅色移到左邊
                temp = nums[l];
                nums[l] = nums[m];
                nums[m] = temp;
                l++, m++;
                break;
            case white:
                m++;
                break;
            case blue:
                // 將藍色移到右邊
                temp = nums[m];
                nums[m] = nums[r];
                nums[r] = temp;
                r--;
                break;
        }
    }
}

// Dutch national flag problem.
// Reference from anwendeng's solution.