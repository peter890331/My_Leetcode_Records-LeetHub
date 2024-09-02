class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // long long sum = 0;
        // for (int chalk_: chalk) sum += chalk_;
        long long sum = accumulate(chalk.begin(), chalk.end(), 0);
        int remain = k % sum;
        for (int i=0; i<chalk.size(); i++){
            if (remain < chalk[i]) return i;
            remain -= chalk[i];
        }
        return 0;
    }
};

// Reference from Solution_Assist's solution.