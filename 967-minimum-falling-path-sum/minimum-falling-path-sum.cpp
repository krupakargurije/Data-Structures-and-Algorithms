class Solution {
    private:
    int helper(vector<vector<int>>& nums,int r,int c,vector<vector<int>>& dp){
        if(r < 0 || c < 0 || c >= nums[0].size())return 1e9;
        if(r == 0)return nums[r][c];

        if(dp[r][c] != 1e9)return dp[r][c];

        int left = nums[r][c] + helper(nums,r-1,c-1,dp);
        int top = nums[r][c] + helper(nums,r-1,c,dp);
        int right = nums[r][c] + helper(nums,r-1,c+1,dp);

        return dp[r][c] = min({left,top,right});
    }
public:
    int minFallingPathSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        int ans = INT_MAX;

        vector<vector<int>>dp(n,vector<int>(m,1e9));

        for(int j = 0;j < m;j++){
            ans = min(ans,helper(nums,n-1,j,dp));
        }
        return ans;
    }
};