class Solution {
    private:
    vector<vector<int>>nums;
    vector<int> delRow = {-1 , 0 , 1 , 0} , delCol = {0 , 1 , 0 ,-1};
    void manhattanDisCalc(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        nums.assign(n , vector<int>(m , 1e9));

        queue<pair<int , pair<int , int>>>q;
        vector<vector<int>>vis(n , vector<int>(m , 0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]){
                    q.push({0 , {i , j}});
                    nums[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            auto [dis, cell] = q.front();
            auto [row, col] = cell;
            q.pop();

            for(int i = 0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 
                && ncol < m && !vis[nrow][ncol]){
                    nums[nrow][ncol] = dis + 1;
                    q.push({dis + 1 , {nrow , ncol}});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[0][0] || grid[n-1][m-1])return 0;
        manhattanDisCalc(grid);

        priority_queue<tuple<int , int , int>>pq;
        vector<vector<int>>vis(n , vector<int>(m , 0));

        pq.push({nums[0][0] , 0 , 0});
        vis[0][0] = 1;

        while(!pq.empty()){
            auto [dis , row , col] = pq.top();pq.pop();

            if(row == n-1 && col == m-1)return dis;

            for(int i = 0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 
                && ncol < m && !vis[nrow][ncol]){
                    int minDis = min(dis , nums[nrow][ncol]);
                    pq.push({minDis , nrow , ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return -1;
    }
};