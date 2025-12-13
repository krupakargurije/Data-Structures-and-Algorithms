class Solution {
public:
    int minPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        dp[0][0] = arr[0][0];

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i == 0 && j == 0)continue;
                else{
                    int left = (i > 0)?dp[i-1][j]:1e9;
                    int up = (j > 0)?dp[i][j-1]:1e9;

                    dp[i][j] = arr[i][j] + min(left,up);
                }
            }
        }
        return dp[n-1][m-1];
    }
};