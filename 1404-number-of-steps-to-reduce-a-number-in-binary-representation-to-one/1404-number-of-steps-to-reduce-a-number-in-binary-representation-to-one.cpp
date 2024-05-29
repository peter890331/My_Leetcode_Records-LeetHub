class Solution {
public:
    int numSteps(string s) {
        int n = s.length();  // 獲取字符串的長度
        int ans = n - 1;     // 初始化步驟計數器，設為n-1，因為至少需要n-1次操作將所有位移除
        int carry = 0;       // 進位，初始化為0

        for (int i = n - 1; i > 0; i--) {   // 從最後一位開始遍歷到第一位
            // cout<<s[i];
            if (s[i] - '0' + carry == 1) {  // 如果當前位加上進位後為1（即是奇數情況）
                ans++;                      // 增加步驟計數
                carry = 1;                  // 設置進位為1，表示將會有進位
            }
        }

        return ans + carry;  // 返回總步驟數，包含最終的進位
    }
};

// shubham6762's solution.