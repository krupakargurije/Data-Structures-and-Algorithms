class Solution {
public:
    int concatenatedBinary(int n) {
        int MOD = 1e9 + 7;
        long long ans = 0;

        for(int i = 1;i<=n;i++){
            int temp = i;
            int len = 0;

            while(temp > 0){
                len++;
                temp >>= 1;
            }

            ans = (((ans << len) % MOD) + i) % MOD;
        }
        return (int)ans;
    }
};