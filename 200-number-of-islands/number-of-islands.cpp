class Solution {
private:
    void bfs(vector<vector<char>>& grid,int row,int col){
        int n = grid.size();
        int m = grid[0].size();
        grid[row][col] = '0';
        queue<pair<int,int>> q;
        q.push({row,col});
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};
            for(int i = 0;i<4;i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >=0 && ncol <m 
                 && grid[nrow][ncol] == '1'){
                    q.push({nrow,ncol});
                    grid[nrow][ncol] = '0';
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int islands = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1'){
                    bfs(grid,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
};