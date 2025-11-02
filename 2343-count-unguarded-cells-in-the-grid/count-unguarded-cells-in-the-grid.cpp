class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, '.'));
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (auto it : guards) {
            int row = it[0], col = it[1];
            grid[row][col] = 'G';
        }
        for (auto it : walls) {
            int row = it[0], col = it[1];
            grid[row][col] = 'W';
        }

        vector<pair<int, int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

        for (auto it : guards) {
            int r = it[0], c = it[1];
            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                while (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                       grid[nr][nc] != 'W' && grid[nr][nc] != 'G') {
                    vis[nr][nc] = 1;
                    nr += dr;
                    nc += dc;
                }
            }
        }

        for (auto it : guards) vis[it[0]][it[1]] = 1;
        for (auto it : walls) vis[it[0]][it[1]] = 1;

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) ans++;
            }
        }
        return ans;
    }
};
