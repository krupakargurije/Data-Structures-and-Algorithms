class Solution {
public:
    double champagneTower(int pour, int row, int glass) {
        vector<vector<double>>dp(101,vector<double>(101,0));
        dp[0][0] =(double) pour;

        for(int i = 0;i< row;i++){
            for(int j = 0;j<=i;j++){
                double extra = (dp[i][j] - 1) / 2;

                if(extra > 0){
                    dp[i+1][j] += extra;
                    dp[i+1][j+1] += extra;
                }
            }
        }
        return min(1.0,dp[row][glass]);
    }
};

//0
//0 1
//0 1 2
//0 1 2 3