class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9 + 7;
        long long ans = 0, temp = 0;
        for(char c : s){
            if(c == '1') temp++;
            else{
                ans = (ans + temp * (temp + 1) / 2) % MOD;
                temp = 0;
            }
        }
        ans = (ans + temp * (temp + 1) / 2) % MOD;
        return ans;
    }
};
