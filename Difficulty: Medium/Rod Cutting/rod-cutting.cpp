// User function Template for C++

class Solution {
    private:
    int helper(vector<int> &prices , int idx , int target , vector<vector<int>> &dp){
        if(idx == 0){
            return target * prices[idx];
        }
        
        if(dp[idx][target] != -1)return dp[idx][target];
        
        int nonPic = helper(prices , idx - 1 , target , dp);
        int pic = 0;
        if(idx + 1 <= target)
            pic = prices[idx] + helper(prices , idx , target - (idx + 1), dp);
        
        return dp[idx][target] = max(pic, nonPic);
    }
  public:
    int cutRod(vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1 , -1));
        return helper(prices , n-1, n, dp);
    }
};