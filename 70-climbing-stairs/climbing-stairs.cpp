class Solution {
    // int helper(int n , vector<int> &dp){
    //     if(n < 0)
    //         return 0;
    //     if(n == 0)
    //         return 1;
    //     if(dp[n] != -1)
    //         return dp[n];

    //     return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    // }
public:
    int climbStairs(int n){
        int curr = 1 , prev = 1;
        
        for(int i = 2;i<=n;i++){
            int temp = curr + prev;
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};