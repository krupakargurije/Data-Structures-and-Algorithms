class Solution {
private:
    bool helper(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, pair<int,int>>> q;
        q.push({{r, c}, {-1, -1}});
        vis[r][c] = 1;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int row = it.first.first;
            int col = it.first.second;
            int parentRow = it.second.first;
            int parentCol = it.second.second;

            for (int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == grid[row][col]) {

                    if (!vis[nrow][ncol]) {
                        vis[nrow][ncol] = 1;
                        q.push({{nrow, ncol}, {row, col}});
                    }
                    else if (!(nrow == parentRow && ncol == parentCol)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (helper(i, j, grid, vis))
                        return true;
                }
            }
        }
        return false;
    }
};