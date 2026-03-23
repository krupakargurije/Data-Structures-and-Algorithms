using ll = long long;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        ll MOD = 1e9 + 7;

        // dp[i][j] = {max product, min product}
        vector<vector<pair<ll,ll>>> dp(
            n, vector<pair<ll,ll>>(m)
        );

        dp[0][0] = {grid[0][0], grid[0][0]};

        // first row
        for(int j = 1; j < m; j++){
            ll val = grid[0][j];
            ll mx = dp[0][j-1].first * val;
            ll mn = dp[0][j-1].second * val;
            dp[0][j] = {mx, mn};
        }

        // first column
        for(int i = 1; i < n; i++){
            ll val = grid[i][0];
            ll mx = dp[i-1][0].first * val;
            ll mn = dp[i-1][0].second * val;
            dp[i][0] = {mx, mn};
        }

        // rest of grid
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                ll val = grid[i][j];

                ll a = dp[i-1][j].first;   // top max
                ll b = dp[i-1][j].second;  // top min
                ll c = dp[i][j-1].first;   // left max
                ll d = dp[i][j-1].second;  // left min

                ll mx = max({a*val, b*val, c*val, d*val});
                ll mn = min({a*val, b*val, c*val, d*val});

                dp[i][j] = {mx, mn};
            }
        }

        ll ans = dp[n-1][m-1].first;

        if(ans < 0) return -1;
        return ans % MOD;
    }
};