class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        q.push({{0,0},1});
        vis[0][0] = 1;

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            int delrow[] = {-1,-1,0,1,1,1,0,-1};
            int delcol[] = {0,1,1,1,0,-1,-1,-1};

            if(x == n-1 && y == n-1)return steps;

            for(int i = 0;i<8;i++){
                int nrow = x + delrow[i];
                int ncol = y + delcol[i];

                if(nrow >= 0 && nrow <n && ncol >= 0 && ncol < n 
                && grid[nrow][ncol] == 0 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},steps+1});
                }
                
            }
        }
        return -1;
    }
};