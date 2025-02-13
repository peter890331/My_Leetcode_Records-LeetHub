int reverse(int x){
    int ans = 0;
    while (x != 0){
        if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)){  // INT_MAX / 10 和 INT_MIN / 10 分別是 int 類型能夠表示的最大和最小值除以 10 的結果。
            return 0;
        }
        ans *= 10;
        ans += x % 10;
        x /= 10;
    }
    return ans;
}