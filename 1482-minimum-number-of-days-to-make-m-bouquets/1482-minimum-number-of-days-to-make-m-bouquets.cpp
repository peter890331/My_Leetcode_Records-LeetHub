class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < (long long)m*k) return -1;
        
        int left = 0;
        int right = 1e9;
        while (left < right) {
            int mid = left+(right-left)/2;
            if (isOK(bloomDay, m, k, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
    
    bool isOK(vector<int>& bloomDay, int m, int k, int mid) {
        int cnt = 0;
        int cur = 0;
        for (int i=0; i<bloomDay.size(); i++) {
            if (bloomDay[i] > mid) {
                cur = 0;
            }
            else {
                cur += 1;
                if (cur == k) {
                    cur = 0;
                    cnt += 1;
                }
            }
            if (cnt >= m) return true;
        }
        return false;
    }
};

// binary search, binary search is O(log n).
// Reference from 【每日一题】1482. Minimum Number of Days to Make m Bouquets, 8/21/2020, https://youtu.be/D_Pq9SqEwsc.