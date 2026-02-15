class Solution {
    private:
    int helper(vector<vector<int>>& arr,int r,int c,vector<vector<int>>& dp){
        if(r < 0 || c < 0)return 1e9;
        if(r == 0 && c == 0)return arr[0][0];

        if(dp[r][c] != INT_MAX)return dp[r][c];

        int top = arr[r][c] + helper(arr,r-1,c,dp);
        int topleft = arr[r][c] + helper(arr,r,c-1,dp);

        return dp[r][c] = min(top,topleft);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));

        return helper(grid,n-1,m-1,dp);
    }
};