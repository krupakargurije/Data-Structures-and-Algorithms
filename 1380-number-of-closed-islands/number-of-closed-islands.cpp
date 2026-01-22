class Solution {
    private:
    int delRow[4] = {-1,0,1,0};
    int delCol[4] = {0,1,0,-1};
    void dfs(vector<vector<int>>& arr,vector<vector<int>>& vis,int r,int c){
        int n = arr.size();
        int m = arr[0].size();

        vis[r][c] = 1;

        for(int i = 0;i<4;i++){
            int row = r + delRow[i];
            int col = c + delCol[i];

            if(row >= 0 && row < n && col >= 0 && col < m
            && arr[row][col] == 0 && !vis[row][col]){
                dfs(arr,vis,row,col);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i = 0;i<n;i++){
            if(arr[i][0] == 0 && !vis[i][0])dfs(arr,vis,i,0);
            if(arr[i][m-1] == 0 && !vis[i][m-1])dfs(arr,vis,i,m-1);
        }
        for(int j = 0;j<m;j++){
            if(arr[0][j] == 0 && !vis[0][j])dfs(arr,vis,0,j);
            if(arr[n-1][j] == 0 && !vis[n-1][j])dfs(arr,vis,n-1,j);
        }

        int ans = 0;
        for(int i = 1;i<n-1;i++){
            for(int j = 1;j<m-1;j++){
                if(arr[i][j] == 0 && !vis[i][j]){
                    ans++;
                    dfs(arr,vis,i,j);
                }
            }
        }
        return ans;
    }
};