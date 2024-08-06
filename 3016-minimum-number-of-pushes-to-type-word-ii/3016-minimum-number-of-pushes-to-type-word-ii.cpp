class Solution {
public:
    static int minimumPushes(string& word) {
        int freq[26]={0};
        print(freq);
        for(char c: word) 
            freq[c-'a']++;
        sort(freq, freq+26);
        print(freq);
    
        int sz=25, ans=0;
        for(; sz>=0 && freq[sz]!=0; sz--){
            ans+=freq[sz]*((25-sz)/8+1);    
        }
        return ans;
    }
    
    static void print(int freq[]) {
        for (int i = 0; i < 26; i++) {
            cout << freq[i] << ',';
        }
        cout << endl;
    }
};

// anwendeng's solution.