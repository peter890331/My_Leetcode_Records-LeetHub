class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size()-1;
        for (int i=0; i<n; i++){
            if (nums[i] > nums[i+1])
                count++;
        }
        if (nums[n] > nums[0])
            count++;

        if (count<2)
            return true;
        else 
            return false;
    }
};

// Reference from Day30__C語言刷LeetCode_Sort, https://ithelp.ithome.com.tw/articles/10350000?sc=rss.qu.