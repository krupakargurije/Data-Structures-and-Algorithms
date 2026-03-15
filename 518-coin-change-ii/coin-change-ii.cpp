using ll = unsigned long long;
class Solution {
public:
    int change(int money, vector<int>& coins) {
        int n = coins.size();

        vector<vector<ll>> dp(n , vector<ll>(money + 1 , 0));

        for(int i = 0; i < n; i++)
            dp[i][0] = 1;

        for(int idx = 0; idx < n; idx++){
            for(int amount = 1; amount <= money; amount++){

                ll nonpick = (idx > 0) ? dp[idx-1][amount] : 0;

                ll pick = 0;
                if(coins[idx] <= amount)
                    pick = dp[idx][amount - coins[idx]];

                dp[idx][amount] = pick + nonpick;
            }
        }
        return (int)dp[n-1][money];
    }
};