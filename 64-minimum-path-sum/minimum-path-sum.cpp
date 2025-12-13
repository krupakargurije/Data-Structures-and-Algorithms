class Solution {
    private:
    int helper(vector<vector<int>>& arr,int row,int col,vector<vector<int>>& dp){
        if(row < 0 || col < 0)return 1e9;
        if(dp[row][col] != -1)return dp[row][col];
        if(row == 0 && col == 0)return dp[0][0] = arr[0][0];

        int up = helper(arr,row-1,col,dp);
        int left = helper(arr,row,col - 1,dp);

        return dp[row][col] = arr[row][col] + min(up, left);
    }
public:
    int minPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(arr,n-1,m-1,dp);
    }
};