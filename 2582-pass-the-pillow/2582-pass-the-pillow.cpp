class Solution {
public:
    int passThePillow(int n, int time) {
        int quotient = round(time/(n-1));
        int remainder = time%(n-1);
        if (quotient%2==1) return (n-remainder);
        else return remainder+1;
    }
};