using ll = long long;
class Solution {
    ll MOD = 1e9 + 7;
    ll power(ll num , ll pow){
        ll res = 1;

        while(pow > 0){
            if(pow & 1){
                res = (res * num) % MOD;
            }

            num = (num * num) % MOD;
            pow >>= 1;
        }
        return res;
    }
public:
    int countGoodNumbers(long long n) {
        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        return (power(5, evenPositions) *
                power(4, oddPositions)) % MOD;
    }
};