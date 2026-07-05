class Solution {
public:
    int MOD = 1e9+7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        board[0][0] = '0';
        board[n-1][n-1] = '0';

        if(n==2 && board[0][1] == 'X' && board[1][0] == 'X'){
            return {0,1};
        }

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,0)));
        dp[0][0][1] = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'X')continue;
                int score = board[i][j] - '0';
                
                //left
                if((i-1 == 0 && j == 0) || (i>0 && dp[i-1][j][0] > 0)){
                    int val = score + dp[i-1][j][0];
                    dp[i][j][0] = val;
                    dp[i][j][1] = dp[i-1][j][1];
                }

                //up
                if((i == 0 && j-1 == 0) || (j>0 && dp[i][j-1][0] > 0)){
                    int val = score + dp[i][j-1][0];
                    if(dp[i][j][0] < val){
                        dp[i][j][0] = val;
                        dp[i][j][1] = dp[i][j-1][1];
                    }
                    else if(dp[i][j][0] == val){
                        dp[i][j][1] = (dp[i][j][1] + dp[i][j-1][1])%MOD;
                    }
                }

                //diagonal
                if((i-1 == 0 && j-1 == 0) || (i>0 && j>0 &&  dp[i-1][j-1][0] > 0)){
                    int val = score + dp[i-1][j-1][0];
                    if(dp[i][j][0] < val){
                        dp[i][j][0] = val;
                        dp[i][j][1] = dp[i-1][j-1][1];
                    }
                    else if(dp[i][j][0] == val){
                        dp[i][j][1] = (dp[i][j][1] + dp[i-1][j-1][1])%MOD;
                    }
                }
            }
        }

        if(dp[n-1][n-1][0] == 0)return {0,0};

        return dp[n-1][n-1];
    }
};