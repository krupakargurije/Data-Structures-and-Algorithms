class Solution {
public:
    int maximumEnergy(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        int ans = INT_MIN;

        // Start from the end
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = nums[i];
            // "two-pointer" step: jump forward by k
            if (i + k < n)
                dp[i] += dp[i + k];
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
