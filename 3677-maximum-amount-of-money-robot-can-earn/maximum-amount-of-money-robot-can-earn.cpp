class Solution {
private:
    int helper(vector<vector<int>>& coins, int r, int c, 
        vector<vector<vector<int>>>& dp, int firstMin, int secondMin) {
        if (r == 0 && c == 0) {
            if (coins[r][c] < 0 && firstMin > 0) return 0;
            return coins[r][c];
        }

        if (dp[r][c][firstMin] != -1e9) return dp[r][c][firstMin];

        int top = -1e9, left = -1e9;

        if (r - 1 >= 0) {
            top = max(top , coins[r][c] + helper(coins, r - 1, c, dp, firstMin, secondMin));
            if (coins[r][c] < 0 && firstMin > 0) {
                top = max(top , 0 + helper(coins, r - 1, c, dp, firstMin - 1, secondMin));
            }
        }

        if (c - 1 >= 0) {
            left = max(left , coins[r][c] + helper(coins, r, c - 1, dp, firstMin, secondMin));
            if (coins[r][c] < 0 && firstMin > 0) {
                left = max(left , 0 + helper(coins, r, c - 1, dp, firstMin - 1, secondMin));
            }
        }
        return dp[r][c][firstMin] = max(top, left);
    }

public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -1e9)));
        return helper(coins, n - 1, m - 1, dp, 2, 0);
    }
};