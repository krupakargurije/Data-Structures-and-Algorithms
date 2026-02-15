class Solution {
public:
    int minimumTotal(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n);

        for(int i = 0; i < n; i++){
            dp[i] = vector<int>(nums[i].size(), INT_MAX);
        }
        dp[0][0] = nums[0][0];
        
        for(int i = 1;i< n;i++){
            for(int j = 0;j <= i;j++){
                if(j < i)
                    dp[i][j] = min(dp[i][j] , nums[i][j] + dp[i-1][j]);
                if(j > 0)
                    dp[i][j] = min(dp[i][j] , nums[i][j] + dp[i-1][j-1]);
            }
        }

        int ans = INT_MAX;
        for(int i = 0;i<n;i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};