class Solution {
    string toBinary(int n){
    string res = "";

    while(n > 0){
        if(n % 2 == 0)
            res = "0" + res;
        else
            res = "1" + res;
        n = n / 2;
    }
    return res;
}
public:
    int binaryGap(int n) {
        string s = toBinary(n);
        int len = s.length();
        int ans = 0;
        
        for(int i = 0,j = 1;j < len;j++){
            if(s[j] == '1'){
                ans = max(ans , abs((len - i) - (len - j)));
                i = j;
            }
        }
        return ans;
    }
};