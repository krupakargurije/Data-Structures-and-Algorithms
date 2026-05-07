class Solution {
    private:
    int helper(vector<int>& cost , int idx , vector<int>& dp){
        if(idx < 0)return 0;

        if(dp[idx] != -1)return dp[idx];

        int one = cost[idx] + helper(cost , idx - 1 , dp);
        int two = cost[idx] + helper(cost , idx - 2 , dp);
        
        return dp[idx] = min(one , two);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n , -1);

        return min(helper(cost , n-1 , dp) , helper(cost , n-2 , dp));
    }
};