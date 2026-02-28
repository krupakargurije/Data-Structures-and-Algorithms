class Solution {
    int helper(int bagWeight, vector<int> &val, vector<int> &wt , int idx , vector<vector<int>> &dp){
        if(idx < 0)return 0;
        
        if(dp[idx][bagWeight] != -1)return dp[idx][bagWeight];
        
        int notPic = helper(bagWeight , val , wt , idx - 1 ,dp);
        
        int pic = 0;
        if(wt[idx] <= bagWeight)
            pic = val[idx] + helper(bagWeight - wt[idx], val , wt , idx - 1 , dp);
            
        return dp[idx][bagWeight] = max(pic , notPic);
    }
  public:
    int knapsack(int w, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>>dp(n , vector<int>(w + 1, -1));
        return helper(w , val , wt , n-1 , dp);
    }
};