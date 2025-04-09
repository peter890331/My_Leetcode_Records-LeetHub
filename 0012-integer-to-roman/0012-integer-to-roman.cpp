class Solution {
public:
    string intToRoman(int num) {
        string ch1[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string ch2[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string ch3[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string ch4[4] = {"", "M", "MM", "MMM"};
        return ch4[num/1000%10] + ch3[num/100%10] + ch2[num/10%10] + ch1[num%10];
    }
};