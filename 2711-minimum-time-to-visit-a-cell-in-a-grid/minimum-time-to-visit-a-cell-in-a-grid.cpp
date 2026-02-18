class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        //pq {time , row , col }
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        vector<vector<int>>dis(n,vector<int>(m , INT_MAX));

        pq.push({0,0,0});
        dis[0][0] = 0;

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        while(!pq.empty()){
            auto [time , r , c] = pq.top();
            pq.pop();

            if(r == n - 1 && c == m - 1)return time;

            if(dis[r][c] < time)continue;

            for(int i = 0;i<4;i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    int next = time + 1;

                    if(next < grid[nrow][ncol]){

                        int diff = grid[nrow][ncol] - next;

                        if(diff % 2 == 0)
                            next = grid[nrow][ncol];
                        else
                            next = grid[nrow][ncol] + 1;
                    }

                    if(next < dis[nrow][ncol]){
                        pq.push({next , nrow , ncol});
                        dis[nrow][ncol] = next;
                    }
                }
            }
        }
        return -1;
    }
};