class Solutions{
    public:
    bool helper(int row,int col,vector<vector<int>>& arr1,vector<vector<int>>& arr2,vector<vector<int>>& vis){
        int n = arr1.size();
        int m = arr1[0].size();
        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};

        bool sub = (arr1[row][col] == 1);

        for(int i = 0;i<4;i++){
            int nrow = delr[i] + row;
            int ncol = delc[i] + col;

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            !vis[nrow][ncol] && arr2[nrow][ncol] == 1){
                vis[nrow][ncol] = 1;
                sub &= helper(nrow,ncol,arr1,arr2,vis);
            }
        }
        return sub;
    }
};
class Solution {
public:
    int countSubIslands(vector<vector<int>>& arr1, vector<vector<int>>& arr2) {
        int n = arr1.size();
        int m = arr1[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        Solutions s;
        int ans = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(arr2[i][j] == 1 && !vis[i][j]){
                    if(s.helper(i,j,arr1,arr2,vis))ans++;
                }
            }
        }
        return ans;
    }
};