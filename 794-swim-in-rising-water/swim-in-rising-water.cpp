class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , 
        greater<pair<int,pair<int,int>>>> pq;

        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        //{time,{row,col}}
        pq.push({grid[0][0],{0,0}});
        dis[0][0] = grid[0][0];

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int time = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == n-1)return time;

            for(int i = 0;i < 4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n){
                    int newTime = max(time,grid[nRow][nCol]);
                    if(newTime < dis[nRow][nCol]){
                        dis[nRow][nCol] = newTime;
                        pq.push({newTime,{nRow,nCol}});
                    }
                }
            }
        }
        return -1;
    }
};