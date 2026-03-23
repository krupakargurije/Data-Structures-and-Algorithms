using ll = long long;
int MOD = 1e9 + 7;
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //dp (max_val , min_val )
        vector<vector<pair< ll , ll >>> dp(n , vector<pair <ll , ll>> (m , { LLONG_MIN , LLONG_MAX}));
        dp[0][0] = {grid[0][0], grid[0][0]};

        for(int r = 1;r < n ;r++){
            ll val = grid[r][0];
            ll mx = dp[r - 1][0].first * val;
            ll mn = dp[r - 1][0].second * val;
            dp[r][0] = {mx, mn};
        }

        for(int c = 1;c<m;c++){
            ll val = grid[0][c];
            ll mx = dp[0][c-1].first * val;
            ll mn = dp[0][c-1].second * val;
            dp[0][c] = {mx, mn};
        }

        for(int r = 1;r<n;r++){
            for(int c = 1;c<m;c++){
                ll val = grid[r][c];
                ll mx = LLONG_MIN , mn = LLONG_MAX;

                auto left = dp[r][c - 1];
                auto top = dp[r - 1][c];

                mx = max({ left.first * val, left.second * val, top.first * val, top.second * val});
                mn = min({ left.first * val, left.second * val, top.first * val, top.second * val});

                dp[r][c] = {mx , mn};
            }
        }
        if(dp[n-1][m-1].first < 0)return -1;
        return dp[n-1][m-1].first % MOD;
    }
};