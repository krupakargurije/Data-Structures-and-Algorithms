const int MOD = 1e9 + 7;

class Fancy {
public:
    vector<long long> arr;
    long long mul = 1;
    long long add = 0;

    long long modPow(long long a,long long b){
        long long res = 1;
        while(b){
            if(b&1) res = (res*a)%MOD;
            a = (a*a)%MOD;
            b >>= 1;
        }
        return res;
    }

    Fancy() {}

    void append(int val) {
        long long x = (val - add + MOD) % MOD;
        x = (x * modPow(mul, MOD-2)) % MOD;
        arr.push_back(x);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if(idx >= arr.size()) return -1;
        return (arr[idx]*mul % MOD + add) % MOD;
    }
};