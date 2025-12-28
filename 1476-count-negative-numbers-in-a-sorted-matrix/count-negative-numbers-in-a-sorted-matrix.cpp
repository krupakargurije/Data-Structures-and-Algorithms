class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int row = 0; row < n; row++) {
            int left = 0, right = m - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (grid[row][mid] < 0) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            ans += (m - left);
        }
        return ans;
    }
};
