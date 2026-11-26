class Solution {
    private:
    int helper(int idx , vector<int> &dp){
        if(idx == 0)return 1;
        if(idx == 1)return 1;

        if(dp[idx] != -1)
            return dp[idx];

        int one = helper(idx - 1 , dp);
        int two = helper(idx - 2 , dp);
        return dp[idx] = one + two;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return helper(n , dp);
    }
};

// n = 3

// 1  2  3  4
// 1  2  3  5