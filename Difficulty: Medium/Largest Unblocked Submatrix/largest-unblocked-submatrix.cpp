class Solution {
  public:
    int largestArea(int n, int m, int k, vector<vector<int>> &arr) {
        vector<int> rows, cols;

        for (auto &x : arr) {
            rows.push_back(x[0]);
            cols.push_back(x[1]);
        }

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        rows.insert(rows.begin(), 0);
        rows.push_back(n + 1);

        cols.insert(cols.begin(), 0);
        cols.push_back(m + 1);

        int maxRow = 0, maxCol = 0;

        for (int i = 1;i < rows.size();i++)
            maxRow = max(maxRow, rows[i] - rows[i - 1] - 1);

        for (int i = 1;i < cols.size();i++)
            maxCol = max(maxCol, cols[i] - cols[i - 1] - 1);

        return maxRow * maxCol;
    }
};