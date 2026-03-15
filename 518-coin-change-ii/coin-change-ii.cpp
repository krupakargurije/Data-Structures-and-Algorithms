class Solution {
    private:
    int helper(int amount , vector<int> &coins,int idx ,vector<vector<int>> &dp){
        if(idx == 0){
            if(amount % coins[0] == 0) return 1;
            return 0;
        }

        if(dp[idx][amount] != -1)return dp[idx][amount];

        int nonpic = helper(amount , coins , idx - 1 ,dp);
        int pic = 0;
        if(coins[idx] <= amount){
            pic = helper(amount - coins[idx] , coins , idx ,dp);
        }
        return dp[idx][amount] = pic + nonpic;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int> (amount + 1 , -1));
        return helper(amount , coins , n - 1, dp);
    }
};