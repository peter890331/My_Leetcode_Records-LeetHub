class Solution {
public:
    string smallestNumber(string pattern) {
        pattern = 'I' + pattern;
        int n = pattern.size();

        int max = 0;
        vector<int> arr;
        for (int i=0; i<n; i++){
            int j = i+1;
            while (j<n && pattern[j]=='D'){
                j++;
            }
            int count = j-i;
            for (int k=max+count; k>max; k--){
                arr.push_back(k);
            }
            max = max+count;
            i = j-1;
        }

        string ans;
        for (int i=0; i<n; i++){
            ans.push_back('0'+arr[i]);
        }
        return ans;
    }
};

// ((I))(I)(I)(ID)(IDDD) = ((1))(2)(3)(54)(9876)
// ((I)DDD) = (4321)
// Reference from 【每日一题】LeetCode 2375. Construct Smallest Number From DI String (aka LC 484. Find Permutation), https://youtu.be/7QXAWuEfWnI.