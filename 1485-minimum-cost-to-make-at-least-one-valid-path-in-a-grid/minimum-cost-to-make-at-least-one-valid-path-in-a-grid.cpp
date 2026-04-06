class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // {cost , row , col}
        priority_queue<pair<int , pair<int , int>> ,
            vector<pair<int , pair<int , int>>> ,
            greater<pair<int , pair<int , int>>>
        >pq;

        vector<vector<bool>> vis(n , vector<bool> ( m, 0));
        vector<int> delRow = {0 ,0 , 0 , 1 , -1};
        vector<int> delCol = {0 ,1 , -1 , 0 , 0};

        pq.push({0 , {0 , 0}});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int currCost = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (vis[r][c]) continue;
            vis[r][c] = 1;

            if(r == n-1 && c == m-1)return currCost;

            for(int i = 1;i <= 4;i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    if(grid[r][c] != i){
                        pq.push({currCost + 1,{nrow , ncol}});
                    }
                    else{
                        pq.push({currCost ,{nrow , ncol}});
                    }
                }
                
            }
        }
        return -1;
    }
};