class Solution {
    private:
    int helper(vector<int> &arr,int target,int idx, vector<vector<int>> &dp){
        if(idx < 0)return 0;
        
        if(idx == 0){
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0 || target == arr[0]) return 1;
            return 0;
        }
        
        if(dp[idx][target] != -1)return dp[idx][target];
        
        int notpic = helper(arr,target ,idx - 1, dp);
        int pic = 0;
        if(arr[idx] <= target)
            pic = helper(arr,target - arr[idx],idx-1 , dp);
        
        return dp[idx][target] = pic + notpic;
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>>dp(n , vector<int>(target + 1 , -1));
        return helper(arr,target,n - 1,dp);
    }
};