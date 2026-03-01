class Solution {
    // private:
    // int helper(vector<int> &coins,int target,int idx ,vector<vector<int>> &dp){
    //     if(idx < 0)return 1e9;
    //     if(idx == 0){
    //         if(target % coins[idx] == 0){
    //             return target/coins[0];
    //         }
    //         else
    //             return 1e9;
    //     }

    //     if(dp[idx][target] != -1)return dp[idx][target];

    //     int nonPic = helper(coins , target , idx - 1 , dp);

    //     int pic = 1e9;
    //     if(coins[idx] <= target)
    //         pic = 1 + helper(coins , target - coins[idx] , idx , dp);

    //     return dp[idx][target] = min(pic , nonPic);
    // }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(amount == 0)return 0;
        vector<vector<int>>dp(n , vector<int>(amount + 1 , 1e9));

        for(int i = 0;i<=amount ; i++){
            if(i % coins[0] == 0)dp[0][i] = i / coins[0];
        }

        // int ans =  helper(coins , amount , n-1 ,dp);
        // return (ans == 1e9) ? -1 : ans;

        for(int idx = 1;idx < n;idx++){
            for(int target = 0;target <= amount;target++){
                int nonPic = dp[idx - 1][target];

                int pic = 1e9;
                if(coins[idx] <= target)
                    pic = 1 + dp[idx][target - coins[idx]];

                dp[idx][target] = min(pic , nonPic);
            }
        }
        return (dp[n - 1][amount] == 1e9) ? -1 : dp[n - 1][amount];
    }
};