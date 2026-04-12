class Solution {
private:
    int getDist(int a, int b) {
        if (a == 26 || b == 26) return 0;

        int r1 = a / 6, c1 = a % 6;
        int r2 = b / 6, c2 = b % 6;

        return abs(r1 - r2) + abs(c1 - c2);
    }

public:
    int minimumDistance(string word) {
        int n = word.size();

        vector<vector<vector<int>>> dp(n,
            vector<vector<int>>(27, vector<int>(27, 1e9)));

        int first = word[0] - 'A';

        // base case
        dp[0][first][26] = 0;
        dp[0][26][first] = 0;

        for (int i = 1; i < n; i++) {
            int curr = word[i] - 'A';

            for (int f1 = 0; f1 < 27; f1++) {
                for (int f2 = 0; f2 < 27; f2++) {

                    if (dp[i-1][f1][f2] == 1e9) continue;

                    // use finger1
                    dp[i][curr][f2] = min(
                        dp[i][curr][f2],
                        dp[i-1][f1][f2] + getDist(f1, curr)
                    );

                    // use finger2
                    dp[i][f1][curr] = min(
                        dp[i][f1][curr],
                        dp[i-1][f1][f2] + getDist(f2, curr)
                    );
                }
            }
        }
        int ans = 1e9;
        for (int f1 = 0; f1 < 27; f1++) {
            for (int f2 = 0; f2 < 27; f2++) {
                ans = min(ans, dp[n-1][f1][f2]);
            }
        }

        return ans;
    }
};