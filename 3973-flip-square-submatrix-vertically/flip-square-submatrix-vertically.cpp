class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>> ans = grid;

        int temp = x;
        for (int i = x + k - 1; i >= x; i--) {
            for (int j = y; j < y + k; j++) {
                ans[temp][j] = grid[i][j];
            }
            temp++;
        }

        return ans;
    }
};