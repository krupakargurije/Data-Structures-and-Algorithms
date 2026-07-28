class Solution {
    private:
    int helper(string &s1 , string &s2 , int i , int j , vector<vector<int>> &dp){
        if(i < 0 || j < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + helper(s1 , s2 , i - 1 , j - 1 , dp);
        }
        return dp[i][j] = max(helper(s1 , s2 , i - 1 , j , dp) , helper(s1 , s2 , i , j - 1 , dp));
    }
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>>dp(n , vector<int>(m , -1));
        return helper(s1 , s2 , n - 1 , m - 1 , dp);
    }
};