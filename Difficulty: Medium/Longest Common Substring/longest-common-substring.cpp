class Solution {
    private:
    int ans = 0;

    int helper(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
            
        helper(s1, s2, i - 1, j, dp);
        helper(s1, s2, i, j - 1, dp);

        if (s1[i] == s2[j]) {
            dp[i][j] = 1 + helper(s1, s2, i - 1, j - 1, dp);
            ans = max(ans, dp[i][j]);
        } else {
            dp[i][j] = 0;
        }
        return dp[i][j];
    }

public:
    int longCommSubstr(string &s1, string &s2) {
        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        helper(s1, s2, n - 1, m - 1, dp);

        return ans;
    }
};