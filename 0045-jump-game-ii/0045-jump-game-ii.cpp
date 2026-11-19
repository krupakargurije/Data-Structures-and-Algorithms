
class Solution {
private:
    int helper(int idx, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();

        if (idx >= n - 1)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int ans = INT_MAX;

        for (int i = 1; i <= nums[idx]; i++) {
            if (idx + i < n) {
                int jumps = helper(idx + i, nums, dp);

                if (jumps != INT_MAX) {
                    ans = min(ans, jumps + 1);
                }
            }
        }

        return dp[idx] = ans;
    }

public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        return helper(0, nums, dp);
    }
};
