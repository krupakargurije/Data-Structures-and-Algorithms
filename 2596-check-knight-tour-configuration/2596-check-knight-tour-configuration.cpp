class Solution {
    vector<int> delRow = {-2, -2, -1, -1, 1, 1, 2, 2};
    vector<int> delCol = {-1, 1, -2, 2, -2, 2, -1, 1};

    // bool helper(vector<vector<int>>& grid, int num, int r, int c) {
    //     int n = grid.size();

    //     if (grid[r][c] != num)
    //         return false;

    //     if (num == n * n - 1)
    //         return true;

    //     for (int i = 0; i < 8; i++){
    //         int nrow = r + delRow[i];
    //         int ncol = c + delCol[i];

    //         if (nrow >= 0 && nrow < n &&
    //             ncol >= 0 && ncol < n &&
    //             grid[nrow][ncol] == num + 1) {

    //             return helper(grid, num + 1, nrow, ncol);
    //         }
    //     }
    //     return false;
    // }

public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0)
            return false;

        int n = grid.size();

        int r = 0 , c = 0;
        int num = 0;
        for(int i = 1;i<n * n;i++){
            bool found = false;
            
            for(int dir = 0;dir < 8;dir++){
                int nrow = r + delRow[dir];
                int ncol = c + delCol[dir];

                if(nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < n &&
                grid[nrow][ncol] == num + 1){
                    
                    found = true;
                    r = nrow;
                    c = ncol;
                    num++;
                    break;
                }
            }
            if(!found)return false;
        }
        return true;
    }
};