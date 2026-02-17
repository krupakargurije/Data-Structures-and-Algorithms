class Solution {
    private:
    bool helper(vector<int>& arr,int sum,int idx,vector<vector<int>>& dp){
        if(sum == 0)return true;
        if(idx == 0)return (arr[0] == sum);
        
        if(dp[idx][sum] != -1)return dp[idx][sum];
        
        bool nonpic = helper(arr,sum,idx-1,dp);
        bool pic = false;
        if(sum >= arr[idx])
            pic = helper(arr,sum - arr[idx],idx-1,dp);
        
        return dp[idx][sum] =  (pic || nonpic);
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        return helper(arr,sum,n-1,dp);
    }
};