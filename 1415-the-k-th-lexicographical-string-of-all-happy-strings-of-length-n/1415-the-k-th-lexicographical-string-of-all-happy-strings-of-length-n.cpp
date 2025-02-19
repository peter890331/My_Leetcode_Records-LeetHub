class Solution {
    string ans;
public:
    string getHappyString(int n, int k) {
        if (k > 3*pow(2, n-1)) return "";       // 無解。
        recursive(n, k-1);                      // k 用 0-index.
        return ans;
    }
private:
    void recursive(int m, int k){

        if (m == 0) return;                     // 結束。

        int t = k / pow(2, m-1);
        char ch = 'a' + t;
        if (!ans.empty() && ch >= ans.back()){
            ch++;
        }
        ans.push_back(ch);

        recursive(m-1, k - t*pow(2, m-1));
    }
};

// Reference from 【每日一题】LeetCode 1415. The k-th Lexicographical String of All Happy Strings of Length n, https://youtu.be/vEBHHzFkKCM.