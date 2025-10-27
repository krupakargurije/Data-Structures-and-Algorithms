class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)return 1;
        int ans = 10,unq = 9;

        for(int i = 2,ave = 9;i <=n;i++,ave--){
            unq *= ave;
            ans += unq;
        }
        return ans;
    }
};