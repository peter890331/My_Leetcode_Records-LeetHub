class Solution {
public:
    bool judgeSquareSum(int c) {
        int a_max = sqrt(c);    // sqrt返回float，只取整數位。
        for (long a=0; a<=a_max; a++){

            // 需注意sqrt的精度問題。
            // round(sqrt(5-1)) = round(sqrt(4)) = round(1.99999999) = 2
            long b = round(sqrt(c - a*a));
            
            if (a*a + b*b == c){
                // cout<<"a="<<a<<", "<<"b="<<b;
                return true;
            }
        }
        return false; 
    }
};

// Reference from 花花酱 LeetCode 633. Sum of Square Numbers - 刷题找工作 EP17, https://youtu.be/2tiZMMTt-CQ.