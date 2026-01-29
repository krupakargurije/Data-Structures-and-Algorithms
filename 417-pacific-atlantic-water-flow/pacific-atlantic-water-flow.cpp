class Solution {
private:
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    void dfs(vector<vector<int>>& arr,
             vector<vector<bool>>& valid,
             int r, int c,
             vector<vector<bool>>& vis) {

        int n = arr.size();
        int m = arr[0].size();

        for (int i = 0; i < 4; i++) {
            int nr = r + delRow[i];
            int nc = c + delCol[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                !vis[nr][nc] &&
                arr[nr][nc] >= arr[r][c]) {

                vis[nr][nc] = true;
                valid[nr][nc] = true;
                dfs(arr, valid, nr, nc, vis);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        vector<vector<bool>> visp(n, vector<bool>(m, false));
        vector<vector<bool>> visa(n, vector<bool>(m, false));
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        // Left & Right borders
        for (int i = 0; i < n; i++) {
            visp[i][0] = true;
            pacific[i][0] = true;
            dfs(arr, pacific, i, 0, visp);

            visa[i][m - 1] = true;
            atlantic[i][m - 1] = true;
            dfs(arr, atlantic, i, m - 1, visa);
        }

        // Top & Bottom borders
        for (int j = 0; j < m; j++) {
            visp[0][j] = true;
            pacific[0][j] = true;
            dfs(arr, pacific, 0, j, visp);

            visa[n - 1][j] = true;
            atlantic[n - 1][j] = true;
            dfs(arr, atlantic, n - 1, j, visa);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};
