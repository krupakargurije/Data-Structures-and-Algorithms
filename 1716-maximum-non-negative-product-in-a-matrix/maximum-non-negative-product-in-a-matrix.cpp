using ll = long long;
int MOD = 1e9 + 7;
class Solution {
    pair<ll , ll> helper(vector<vector<int>>& grid , int r , int c , vector<vector<pair<ll , ll >>>& dp){
        if(r < 0 || c < 0)return { LLONG_MIN , LLONG_MAX};
        if(r == 0 && c == 0)return {grid[0][0] , grid[0][0]};

        if(dp[r][c].first != LLONG_MIN)return dp[r][c];

        auto left = helper(grid , r , c - 1 , dp);
        auto top = helper(grid , r - 1 , c , dp);

        ll val = grid[r][c];
        ll mx = LLONG_MIN;
        ll mn = LLONG_MAX;

        if(left.first != LLONG_MIN){
            mx = max(mx, max(left.first * val, left.second * val));
            mn = min(mn, min(left.first * val, left.second * val));
        }

        if(top.first != LLONG_MIN){
            mx = max(mx, max(top.first * val, top.second * val));
            mn = min(mn, min(top.first * val, top.second * val));
        }

        return dp[r][c] = {mx , mn};
    }
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //dp (max_val , min_val )
        vector<vector<pair< ll , ll >>> dp(n , vector<pair <ll , ll>> (m , { LLONG_MIN , LLONG_MAX}));

        auto ans =  helper(grid , n-1 , m-1 , dp);
        if(ans.first < 0)return -1;
        return ans.first % MOD;
    }
};