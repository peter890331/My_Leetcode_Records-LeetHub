class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;

        int a = 1;
        int b = x;
        long long m = 0;
        while (a <= b){
            m = a + (b - a) / 2;
            cout<<"a: "<<a<<", b: "<<b<<", m: "<<m<<endl;
            long long square = m * m;
            if (square > x){
                b = m - 1;
            }
            else if (square == x){
                return m;
            }
            else {
                a = m + 1;
            }
        }
        return round(b);
    } 
};

// binary search.