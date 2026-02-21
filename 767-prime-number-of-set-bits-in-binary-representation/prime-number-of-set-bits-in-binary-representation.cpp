int MAX = 100;
static vector<bool>prime;
static bool flag = false;
class Solution {
    private:
    void primeFun(){
        prime.assign(MAX + 1,true);
        prime[0] = prime[1] = false;
        for(int i = 2;i * i <= MAX;i++){
            if(prime[i]){
                for(int j = i * i;j <= MAX;j+= i){
                    prime[j] = false;
                }
            }
        }
        flag = true;
    }

public:
    int countPrimeSetBits(int left, int right) {
        if(!flag)
            primeFun();
        
        int ans = 0;
        for(int i = left;i<= right;i++){
            int count = __builtin_popcount(i);
            if(prime[count])ans++;
        }
        return ans;
    }
};