class Solution {
    vector<int> delRow = {-2, -2, -1, -1, 1, 1, 2, 2};
    vector<int> delCol = {-1, 1, -2, 2, -2, 2, -1, 1};

    bool helper(vector<vector<int>>& grid, int num, int r, int c) {
        int n = grid.size();

        if (grid[r][c] != num)
            return false;

        if (num == n * n - 1)
            return true;

        for (int i = 0; i < 8; i++) {
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < n &&
                grid[nrow][ncol] == num + 1) {

                return helper(grid, num + 1, nrow, ncol);
            }
        }
        return false;
    }

public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0)
            return false;

        return helper(grid, 0, 0, 0);
    }
};