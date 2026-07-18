class Solution {
public:
    int findGCD(vector<int>& nums) {
        int s = 1001;
        int l = 0;

        for(int i : nums){
            s = min(s , i);
            l = max(l , i);
        }
        return gcd(s , l);
    }
};