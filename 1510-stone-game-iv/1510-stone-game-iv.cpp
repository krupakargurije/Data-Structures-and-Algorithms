class Solution {
    private:
    vector<int>dp;
    // bool helper(int n){
    //     if(n == 0)
    //         return false;
        
    //     if(dp[n] != -1)
    //         return dp[n];

    //     for(int i = 1;i * i <= n;i++){
    //         if(!helper(n - i * i))
    //             return dp[n] = true;
    //     }
    //     return dp[n] = false;
    // }
public:
    bool winnerSquareGame(int n) {
        dp.assign(n + 1 , 0);
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j * j <= i;j++){
                if(!dp[i - j * j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};