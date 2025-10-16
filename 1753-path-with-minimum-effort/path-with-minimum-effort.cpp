class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, 
        greater<pair<int, pair<int,int>>>> pq;

        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        pq.push({0,{0,0}});
        dis[0][0] = 0;

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        while(!pq.empty()){
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            int maxDis = pq.top().first;
            pq.pop();

            if(r == n-1 && c == m-1)return maxDis;

            for(int i = 0;i < 4;i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    int newDis = max(abs(grid[r][c] - grid[nrow][ncol]),maxDis);
                    if(newDis < dis[nrow][ncol]){
                        pq.push({newDis,{nrow,ncol}});
                        dis[nrow][ncol] = newDis;
                    }
                }
            }
        }
        return 0;
    }
};