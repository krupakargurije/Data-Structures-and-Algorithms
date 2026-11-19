
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans = matrix;

        for (int row = 0; row < n; row++){
            for (int col = 0; col < n; col++){
                ans[col][n - 1 - row] = matrix[row][col];
            }
        }
        matrix = ans;
    }
};
