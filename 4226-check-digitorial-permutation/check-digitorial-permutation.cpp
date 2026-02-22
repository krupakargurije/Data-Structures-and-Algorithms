class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> fac = {1,1,2,6,24,120,720,5040,40320,362880};

        int temp = n;
        int sum = 0;

        while(temp){
            sum += fac[temp % 10];
            temp /= 10;
        }

        vector<int> cnt1(10,0), cnt2(10,0);

        while(n){
            cnt1[n % 10]++;
            n /= 10;
        }

        while(sum){
            cnt2[sum % 10]++;
            sum /= 10;
        }

        return cnt1 == cnt2;
    }
};