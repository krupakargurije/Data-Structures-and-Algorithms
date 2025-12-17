class Solution 
{
public:
    long long helper(int ind, int n, vector<int>& prices, int k, int canBuy, int type,
                     vector<vector<vector<vector<long long>>>> &dp)
    {
        if(ind == n || k == 0){
            if(canBuy == 1) return 0;
            return -1e9;
        }

        int t = type + 1;

        if(dp[ind][k][canBuy][t] != LLONG_MIN) return dp[ind][k][canBuy][t];

        long long res;

        if(canBuy == 1){
            long long buy    = -1LL * prices[ind] + helper(ind+1, n, prices, k, 0, 0, dp);
            long long shtBuy =  1LL * prices[ind] + helper(ind+1, n, prices, k, 0, 1, dp);
            long long skip   = helper(ind+1, n, prices, k, 1, -1, dp);

            res = max({buy, shtBuy, skip});
        }
        else{
            long long sell = 0;

            if(type == 0)  
                sell =  1LL * prices[ind] + helper(ind+1, n, prices, k-1, 1, -1, dp);
            else if(type == 1)
                sell = -1LL * prices[ind] + helper(ind+1, n, prices, k-1, 1, -1, dp);

            long long skip = helper(ind+1, n, prices, k, 0, type, dp);

            res = max(sell, skip);
        }

        return dp[ind][k][canBuy][t] = res;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

        vector<vector<vector<vector<long long>>>> dp(
            n, vector<vector<vector<long long>>>(
                k+1, vector<vector<long long>>(
                    2, vector<long long>(3, LLONG_MIN)
                )
            )
        );
        return helper(0, n, prices, k, 1, -1, dp);
    }
};