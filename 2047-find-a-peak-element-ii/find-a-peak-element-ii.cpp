class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int left = 0;
        int right = m - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Find maximum element in the middle column
            int maxRow = 0;

            for (int row = 0; row < n; row++) {
                if (mat[row][mid] > mat[maxRow][mid]) {
                    maxRow = row;
                }
            }

            int leftVal = (mid - 1 >= 0)
                            ? mat[maxRow][mid - 1]
                            : -1;

            int rightVal = (mid + 1 < m)
                            ? mat[maxRow][mid + 1]
                            : -1;

            if (mat[maxRow][mid] > leftVal &&
                mat[maxRow][mid] > rightVal) {
                return {maxRow, mid};
            }

            else if (leftVal > mat[maxRow][mid]) {
                right = mid - 1;
            }

            else {
                left = mid + 1;
            }
        }
        return {-1, -1};
    }
};