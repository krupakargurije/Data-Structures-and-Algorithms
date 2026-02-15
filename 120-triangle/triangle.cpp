class Solution {
    private:
    int helper(vector<vector<int>>& nums,int r,int c,vector<vector<int>>& dp){
        if(r == nums.size() - 1)return nums[r][c];

        if(dp[r][c] != INT_MAX)return dp[r][c];

        int down = nums[r][c] + helper(nums,r+1,c,dp);
        int rightdown = nums[r][c] + helper(nums,r+1,c+1,dp);

        return dp[r][c] = min(down,rightdown);
    }
public:
    int minimumTotal(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n);

        for(int i = 0; i < n; i++){
            dp[i] = vector<int>(nums[i].size(), INT_MAX);
        }

        return helper(nums,0,0,dp);
    }
};