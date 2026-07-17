class Solution {
private:
    const int NEG = -1e6;
    vector<vector<int>> dp;

    int helper(vector<int>& nums, int idx, int target) {
        if (target == 0)
            return 0;

        if (idx == nums.size() || target < 0)
            return NEG;

        if (dp[idx][target] != -1)
            return dp[idx][target];

        int notTake = helper(nums, idx + 1, target);

        int take = NEG;
        if (nums[idx] <= target)
            take = 1 + helper(nums, idx + 1, target - nums[idx]);

        return dp[idx][target] = max(take, notTake);
    }

public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        dp.assign(nums.size(), vector<int>(target + 1, -1));
        int ans = helper(nums, 0, target);
        return (ans < 0 ? -1 : ans);
    }
};