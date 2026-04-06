class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        vector<int> delRow = {0 ,0 , 0 , 1 , -1};
        vector<int> delCol = {0 ,1 , -1 , 0 , 0};

        pq.push({0 , {0 , 0}});
        dist[0][0] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int currCost = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(currCost > dist[r][c]) continue;

            if(r == n-1 && c == m-1) return currCost;

            for(int i = 1; i <= 4; i++){
                int nr = r + delRow[i];
                int nc = c + delCol[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    int newCost = currCost + (grid[r][c] == i ? 0 : 1);

                    if(newCost < dist[nr][nc]){
                        dist[nr][nc] = newCost;
                        pq.push({newCost , {nr , nc}});
                    }
                }
            }
        }
        return -1;
    }
};