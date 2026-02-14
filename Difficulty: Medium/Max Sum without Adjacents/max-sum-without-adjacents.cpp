// User function template for C++
class Solution {
    private:
    int helper(vector<int>& arr,int idx,vector<int>& dp){
        if(idx < 0)return 0;
        if(idx == 0)return arr[0];
        
        if(dp[idx] != -1)return dp[idx];
        
        int pic = helper(arr,idx-2,dp) + arr[idx];
        int nonpic = helper(arr,idx - 1,dp);
        
        return dp[idx] = max(pic,nonpic);
    }
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n,-1);
        return helper(arr,n-1,dp);
    }
};