class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        health -= grid[0][0];
        if (health <= 0) return false;

        vector<vector<int>> best(m, vector<int>(n, -1));
        queue<tuple<int, int, int>> q;

        q.push({0, 0, health});
        best[0][0] = health;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c, h] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1)
                return true;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int nh = h - grid[nr][nc];

                if (nh > 0 && nh > best[nr][nc]) {
                    best[nr][nc] = nh;
                    q.push({nr, nc, nh});
                }
            }
        }

        return false;
    }
};