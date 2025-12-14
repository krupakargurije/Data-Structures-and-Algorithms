class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base case: first row
        for (int j = 0; j < m; j++) {
            dp[0][j] = arr[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = dp[i - 1][j];
                int left = (j > 0) ? dp[i - 1][j - 1] : 1e9;
                int right = (j < m - 1) ? dp[i - 1][j + 1] : 1e9;

                dp[i][j] = arr[i][j] + min({up, left, right});
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
