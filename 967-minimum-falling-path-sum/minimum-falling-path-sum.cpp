class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        int ans = 1e9;

        vector<vector<int>>dp(n,vector<int>(m,1e9));

        for(int i = 0;i<n;i++)dp[0][i] = nums[0][i];

        for(int i = 1;i<n;i++){
            for(int j = 0;j<m;j++){
                int left = (j > 0) ? dp[i-1][j-1] : 1e9;
                int top = dp[i-1][j];
                int right = (j < m-1) ? dp[i-1][j+1] : 1e9;

                dp[i][j] =nums[i][j] + min({left,top,right});
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};