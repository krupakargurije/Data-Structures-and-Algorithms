class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int ans = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int delr[4] = {-1, 0, 1, 0};
        int delc[4] = {0, 1, 0, -1};

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(arr[i][j] == 1 && !vis[i][j]){
                    int area = 0;
                    queue<pair<int,int>> q;

                    q.push({i, j});
                    vis[i][j] = 1;

                    while(!q.empty()){
                        auto [row, col] = q.front();
                        q.pop();
                        area++;

                        for(int d = 0; d < 4; d++){
                            int nrow = row + delr[d];
                            int ncol = col + delc[d];

                            if(nrow >= 0 && nrow < n &&
                               ncol >= 0 && ncol < m &&
                               arr[nrow][ncol] == 1 &&
                               !vis[nrow][ncol]){

                                vis[nrow][ncol] = 1;
                                q.push({nrow, ncol});
                            }
                        }
                    }
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};
