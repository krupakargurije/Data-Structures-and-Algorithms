
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        bool firstRow = false;
        bool firstCol = false;

        // Check whether first row contains zero
        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == 0)
                firstRow = true;
        }

        // Check whether first column contains zero
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0)
                firstCol = true;
        }

        // Mark rows and columns using first row and column
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set marked cells to zero
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero the first row if needed
        if (firstRow) {
            for (int j = 0; j < m; j++)
                matrix[0][j] = 0;
        }

        // Zero the first column if needed
        if (firstCol) {
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;
        }
    }
};
