class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        vector<int>prev(m,0),curr(m,0);

        // Base case: first row
        for (int j = 0; j < m; j++) {
            prev[j] = arr[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = (i > 0)?prev[j]:1e9;
                int left = (j > 0) ? prev[j - 1] : 1e9;
                int right = (j < m - 1) ? prev[j + 1] : 1e9;

                curr[j] = arr[i][j] + min({up, left, right});
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};
