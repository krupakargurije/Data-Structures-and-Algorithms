class Solution {
    private:
    int helper(vector<int>& val, vector<int>& wt , int idx, int capacity, vector<vector<int>> &dp){
        if(idx == 0){
            return (wt[0]) ? ((capacity / wt[0]) * val[0]) : 0;
        }
        
        
        if(dp[idx][capacity] != -1)return dp[idx][capacity];
        
        int nonPic = helper(val , wt , idx - 1, capacity , dp);
        
        int pic = 0;
        if(wt[idx] <= capacity)
            pic = val[idx] + helper(val , wt , idx , capacity - wt[idx], dp);
        
        return dp[idx][capacity] = max(pic , nonPic);
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
       int n =  val.size();
       
       vector<vector<int>> dp(n , vector<int> (capacity + 1, -1));
       
       return helper(val , wt , n-1,capacity , dp);
    }
};