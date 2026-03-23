using ll = long long;
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 1e9 + 7;

        queue<pair<int , int>>q;
        vector<vector<ll>> maxDis(n , vector<ll> (m , LLONG_MIN));
        vector<vector<ll>> minDis(n , vector<ll> (m , LLONG_MAX));

        q.push({ 0 , 0});
        maxDis[0][0] = minDis[0][0] = grid[0][0];
        int delRow[] = {0 , 1};
        int delCol[] = {1 , 0};

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int r = it.first;
            int c = it.second;

            for(int i = 0;i<2;i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    ll val = grid[nrow][ncol];

                    ll mx = max(maxDis[r][c] * val , minDis[r][c] * val);
                    ll mn = min(maxDis[r][c] * val , minDis[r][c] * val);

                    if(mx > maxDis[nrow][ncol] || mn < minDis[nrow][ncol]){
                        maxDis[nrow][ncol] = max(maxDis[nrow][ncol] , mx);
                        minDis[nrow][ncol] = min(minDis[nrow][ncol] , mn);
                        q.push({nrow , ncol});
                    }
                }
            }
        }
        if(maxDis[n-1][m-1] < 0)return -1;
        return maxDis[n-1][m-1] % MOD;
    }
};