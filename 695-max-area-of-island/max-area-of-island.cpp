class Solution {
    private:
    int helper(int r , int c , vector<vector<int>>& grid , vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int , int>>q;
        int delRow[] = {-1 , 0 , 1 , 0};
        int delCol[] = {0 , 1 , 0 , -1};

        q.push({r , c});
        vis[r][c] = 1;

        int area = 0;
        while(!q.empty()){
            auto [row , col] = q.front();
            q.pop();
            area++;

            for(int i = 0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && grid[nrow][ncol] && !vis[nrow][ncol]){
                    q.push({nrow , ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n , vector<int>(m , 0));
        int ans = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j]){
                    int curr = helper(i , j , grid , vis);
                    ans = max(ans , curr);
                }
            }
        }
        return ans;
    }
};