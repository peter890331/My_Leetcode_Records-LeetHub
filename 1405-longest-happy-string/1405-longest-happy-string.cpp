class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        int a_nums = 0;
        int b_nums = 0;
        int c_nums = 0;
        int count = 0;
        int max = a + b + c;
        int i = 0;

        while (i < max){
            if ((a>=b && a>=c && a_nums!=2) || (a>0 && (b_nums == 2 || c_nums == 2))){
                ans += 'a';
                a_nums++;
                b_nums = 0;
                c_nums = 0;
                a--;
            }
            else if ((b>=a && b>=c && b_nums!=2) || (b>0 && (a_nums == 2 || c_nums == 2))){
                ans += 'b';
                b_nums++;
                a_nums = 0;
                c_nums = 0;
                b--;
            }
            else if ((c>=a && c>=b && c_nums!=2) || (c>0 && (a_nums == 2 || b_nums == 2))){
                ans += 'c';
                c_nums++;
                a_nums = 0;
                b_nums = 0;
                c--;
            }
            i++;
        }
        return ans;
    }
};

// Reference from vinod_aka_veenu's solution.