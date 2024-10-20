class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stackOp;
        stack<vector<bool>> stackNums;
        vector<bool> nums;
        bool ans;
        for (int i=0; i<expression.size(); i++){
            if (expression[i]=='!' || expression[i]=='&' || expression[i]=='|'){
                stackOp.push(expression[i]);
                stackNums.push(nums);
                nums.clear();
                i++;
            }
            else if (expression[i]==')'){
                ans = calculate(stackOp.top(), nums);
                stackOp.pop();
                nums = stackNums.top();
                nums.push_back(ans);
                stackNums.pop();
            }
            else if (expression[i]=='t' || expression[i]=='f'){
                nums.push_back(expression[i]=='t');
            }
        }
        return ans;
    }

    int calculate(char Op, vector<bool>& nums){
        bool ans;
        if (Op=='!'){
            ans = !nums[0];
        }
        else if (Op=='&'){
            for (int i=0; i<nums.size(); i++){
                ans &= nums[i];
            }
        }
        else if (Op=='|'){
            for (int i=0; i<nums.size(); i++){
                ans |= nums[i];
            }
        }
        return ans;
    }
};