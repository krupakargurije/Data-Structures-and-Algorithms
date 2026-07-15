class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int eve = 0 , odd = 0;

        for(int i = 1;i<=n * 2;i++){
            if(i % 2 != 0)odd += i;
            else eve += i;
        }
        return gcd(odd , eve);
    }
};