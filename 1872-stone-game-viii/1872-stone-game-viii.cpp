class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> prefix(n);
        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        // dp[n - 1]
        int prev = prefix[n - 1];

        for (int i = n - 2; i >= 1; i--) {
            int pick = prefix[i] - prev;
            int skip = prev;

            prev = max(pick, skip);
        }
        return prev;
    }
};