class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>>dp(n, vector<bool>(sum+1, 0));
        for(int i = 0;i<n;i++)dp[i][0] = true;
        
        dp[0][arr[0]] = true;
        
        for(int idx = 1;idx <n;idx++){
            for(int target = 1;target <= sum;target++){
                bool notTake = dp[idx - 1][target];
                bool take = false;
                if(target >= arr[idx])
                    take = dp[idx-1][target - arr[idx]];
                    
                dp[idx][target] = take || notTake;
            }
        }
        return dp[n - 1][sum];
    }
};