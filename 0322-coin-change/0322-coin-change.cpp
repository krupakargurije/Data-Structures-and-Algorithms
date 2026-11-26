class Solution {
    private:
    int helper(int idx , vector<int> &coins , int target , vector<vector<int>> &dp){
        if(idx == 0){
            if(target % coins[0] == 0)
                return target / coins[0];
            else 
                return 1e9;
        }

        if(dp[idx][target] != -1)
            return dp[idx][target];

        int skip = helper(idx - 1 , coins , target , dp);
        int pic = 1e9;
        
        if(coins[idx] <= target)
            pic = 1 + helper(idx , coins , target - coins[idx] , dp);

        return dp[idx][target] = min(pic , skip);
    }
public:
    int coinChange(vector<int>& coins, int amount){
        int n = coins.size();
        vector<vector<int>>dp(n , vector<int> (amount + 1 , -1));
        int ans =  helper(n - 1 , coins , amount , dp);
        return ans >= 1e9 ? -1 : ans;
    }
};