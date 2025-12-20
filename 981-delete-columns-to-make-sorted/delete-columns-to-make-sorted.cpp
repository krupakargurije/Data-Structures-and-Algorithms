class Solution {
public:
    int minDeletionSize(vector<string>& arr) {
        int rows = arr.size();
        int cols = arr[0].size();
        int ans = 0;

        for (int c = 0; c < cols; c++) {
            for (int r = 0; r < rows - 1; r++) {
                if (arr[r][c] > arr[r + 1][c]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
