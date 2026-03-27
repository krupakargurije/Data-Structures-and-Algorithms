class Solution {
private:
    int helper(string &s, int idx, vector<int> &dp) {
        if (idx < 0) return 1;
        if (idx == 0) return s[0] != '0';

        if (dp[idx] != -1) return dp[idx];

        int one = 0, two = 0;

        // take 1 digit
        if (s[idx] != '0') {
            one = helper(s, idx - 1, dp);
        }

        // take 2 digits
        if (s[idx - 1] == '1' || (s[idx - 1] == '2' && s[idx] <= '6')) {
            two = helper(s, idx - 2, dp);
        }
        return dp[idx] = one + two;
    }

public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int n = s.length();
        vector<int> dp(n, -1);
        return helper(s, n - 1, dp);
    }
};