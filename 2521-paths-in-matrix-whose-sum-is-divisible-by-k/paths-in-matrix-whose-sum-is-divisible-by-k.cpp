#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1'000'000'007;
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;

        // dp[i][j][r] = ways to reach (i,j) with sum % k == r
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k, 0))
        );

        int startRem = ((grid[0][0] % k) + k) % k;
        dp[0][0][startRem] = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) continue;

                // from top (i-1, j)
                if (i > 0) {
                    for (int r = 0; r < k; ++r) {
                        int ways = dp[i-1][j][r];
                        if (ways == 0) continue;
                        int newRem = (r + grid[i][j]) % k;
                        dp[i][j][newRem] = (dp[i][j][newRem] + ways) % MOD;
                    }
                }

                // from left (i, j-1)
                if (j > 0) {
                    for (int r = 0; r < k; ++r) {
                        int ways = dp[i][j-1][r];
                        if (ways == 0) continue;
                        int newRem = (r + grid[i][j]) % k;
                        dp[i][j][newRem] = (dp[i][j][newRem] + ways) % MOD;
                    }
                }
            }
        }
        return dp[n-1][m-1][0];
    }
};
