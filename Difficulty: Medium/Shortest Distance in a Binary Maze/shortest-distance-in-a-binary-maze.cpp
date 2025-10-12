// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
    pair<int, int> dst) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[src.first][src.second] == 0 || grid[dst.first][dst.second] == 0)return -1;
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        q.push({src,0});
        vis[src.first][src.second] = 1;
        
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            if(x == dst.first && y == dst.second)return steps;
            
            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};
            
            for(int i = 0;i<4;i++){
                int nrow = x + delrow[i];
                int ncol = y + delcol[i];
                
                if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m 
                && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                    
                    q.push({{nrow,ncol},steps+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return -1;
    }
};
