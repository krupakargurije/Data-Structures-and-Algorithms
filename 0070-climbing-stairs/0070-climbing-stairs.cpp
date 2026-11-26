class Solution {
    // private:
    // int helper(int idx , vector<int> &dp){
    //     if(idx == 0)return 1;
    //     if(idx == 1)return 1;

    //     if(dp[idx] != -1)
    //         return dp[idx];

    //     int one = helper(idx - 1 , dp);
    //     int two = helper(idx - 2 , dp);
    //     return dp[idx] = one + two;
    // }
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2)return n;
        // vector<int> dp(n + 1, 0);
        // return helper(n , dp);

        // dp[0] = 1;
        int prev = 1;
        int curr = 2;

        for(int i = 3;i<=n;i++){
            int temp = prev + curr;

            prev = curr;
            curr = temp;
        }
        return curr;
    }
};

// n = 3

// 1  2  3  4
// 1  2  3  5