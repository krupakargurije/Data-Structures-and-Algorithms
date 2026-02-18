class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s = "";
        while( n > 0){
            s += (n & 1) + '0';
            n >>= 1;
        }


        for(int i = 1;i<s.length();i++){
            if(s[i] == s[i-1])return false;
        }
        return true;
    }
};