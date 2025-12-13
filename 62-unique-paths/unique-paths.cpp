class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j < m;j++){
                if(i == 0 && j == 0)dp[i][j] = 1;
                else{
                    int right = (j > 0)?dp[i][j-1]:0;
                    int down = (i > 0)?dp[i-1][j]:0;
                    dp[i][j] = right + down;
                }
            }
        }
        return dp[n-1][m-1];
    }
};