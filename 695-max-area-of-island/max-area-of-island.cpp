class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        // boundary or water
        if (r < 0 || r >= n || c < 0 || c >= m || arr[r][c] == 0)
            return 0;

        arr[r][c] = 0;
        int area = 1;

        area += dfs(r - 1,c,arr);
        area += dfs(r + 1,c,arr);
        area += dfs(r,c - 1,arr);
        area += dfs(r,c + 1,arr);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j<m; j++) {
                if (arr[i][j] == 1) {
                    ans = max(ans,dfs(i, j, arr));
                }
            }
        }
        return ans;
    }
};
