class Solutions{
    public:
        void helper(int row,int col,vector<vector<int>>& arr,vector<vector<int>>& vis,int& ans){
        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};
        int n = arr.size();
        int m = arr[0].size();
        int sides = 0;

        for(int k = 0;k<4;k++){
            int srow = row + delr[k];
            int scol = col + delc[k];
            if(srow < 0 || srow >= n || scol < 0 || scol >= m || arr[srow][scol] != 1)sides++;
        }
        ans += sides;

        for(int i = 0;i<4;i++){
            int nrow = delr[i] + row;
            int ncol = delc[i] + col;

            if(nrow >= 0 && nrow < n && ncol >= 0&& ncol < m &&
             !vis[nrow][ncol] && arr[nrow][ncol] == 1){
                vis[nrow][ncol] = 1;
                helper(nrow,ncol,arr,vis,ans);
            }
        }
    }
};
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int ans = 0;

        vector<vector<int>>vis(n,vector<int>(m,0));
        Solutions s;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(arr[i][j] == 1){
                    vis[i][j] = 1;
                    s.helper(i,j,arr,vis,ans);
                    return ans;
                }
            }
        }
        return 0;
    }
};