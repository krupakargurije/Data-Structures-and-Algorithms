class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        int s = k % n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    // Even row: left shift by s
                    if (mat[i][j] != mat[i][(j + s) % n]) return false;
                } else {
                    // Odd row: right shift by s
                    if (mat[i][j] != mat[i][(j - s + n) % n]) return false;
                }
            }
        }
        return true;
    }
};