class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<pair<int,int>>> directions = {
            {},
            {{0,-1},{0,1}},     // 1
            {{-1,0},{1,0}},     // 2
            {{0,-1},{1,0}},     // 3
            {{0,1},{1,0}},      // 4
            {{0,-1},{-1,0}},    // 5
            {{0,1},{-1,0}}      // 6
        };

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        q.push({0,0});
        vis[0][0] = 1;

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            if(row == n-1 && col == m-1) return true;

            for(auto [dr, dc] : directions[grid[row][col]]) {
                int nr = row + dr;
                int nc = col + dc;

                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if(vis[nr][nc]) continue;

                for(auto [ndr, ndc] : directions[grid[nr][nc]]) {
                    if(nr + ndr == row && nc + ndc == col) {
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                        break;
                    }
                }
            }
        }

        return false;
    }
};