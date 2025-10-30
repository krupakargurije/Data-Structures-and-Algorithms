class Solution {
    vector<int> dp;
    int helper(vector<int>& height,int n){
        if(n == 0)return 0;
        if(dp[n] != -1)return dp[n];
        
        
        int left = helper(height,n-1) + abs(height[n] - height[n-1]);
        
        int right = INT_MAX;
        if(n > 1)
            right = helper(height,n -2) + abs(height[n] - height[n-2]);
        
        return dp[n] = min(left,right);
    }
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        dp.resize(n,-1);
        if(n == 0 || n == 1)return 0;
        return helper(height,n-1);
    }
};