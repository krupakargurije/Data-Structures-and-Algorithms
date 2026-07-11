class Solution {
public:
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    int dfs(vector<vector<int>>& nums, vector<vector<int>>& vis,
            int r, int c, int xd, int yd) {

        if (r == xd && c == yd)
            return 0;

        vis[r][c] = 1;
        int ans = -1;

        for (int i = 0; i < 4; i++) {
            int row = r + delRow[i];
            int col = c + delCol[i];

            if (row >= 0 && row < nums.size() &&
                col >= 0 && col < nums[0].size() &&
                nums[row][col] == 1 &&
                !vis[row][col]) {

                int dist = dfs(nums, vis, row, col, xd, yd);

                if (dist != -1)
                    ans = max(ans, dist + 1);
            }
        }
        vis[r][c] = 0;
        return ans;
    }

    int longestPath(vector<vector<int>>& nums, int xs, int ys, int xd, int yd) {
        int n = nums.size();
        int m = nums[0].size();

        if (nums[xs][ys] == 0 || nums[xd][yd] == 0)
            return -1;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        return dfs(nums, vis, xs, ys, xd, yd);
    }
};