class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<tuple< int , int , int>>q;
        // vector<vector<int>>vis (n , vector<int>(m , 0));

        for(int i = 0;i<n;i++){ // n * m
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i , j , 0});
                    grid[i][j] = -1;
                    // vis[i][j] = 1;
                }
            }
        }
        int delRow[] = {-1 , 0 , 1 , 0};
        int delCol[] = {0 , 1 , 0 , -1};
        int ans = 0;

        while(!q.empty()){ // n * m 
            auto [r , c , time] = q.front();
            q.pop();
            ans = max(ans , time);

            for(int i = 0;i<4;i++){
                int nRow = r + delRow[i];
                int nCol = c + delCol[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1){

                    // vis[nRow][nCol] = 1;
                    q.push({nRow , nCol , time + 1});
                    grid[nRow][nCol] = -1;
                }
            }
        }

        for(int i = 0;i<n;i++){ // O(n * m)
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return ans;
    }
};

//  bfs 
//   pq -> (row , col , time )
//     vis n * m 

//     1 ->  row , col , 0
//     while pq is not empty 
//         row , col , time 

//         mark them vis -> time + 1

//         push(row , col , time + 1)

//         if !vis && gris[i][j] == 1:
//             -1
//     ans;