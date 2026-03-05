class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;

        for(int x : nums) sum += x;

        if(abs(target) > sum) return 0;

        int offset = sum;

        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, 0));

        // Base case for index 0
        dp[0][nums[0] + offset] += 1;
        dp[0][-nums[0] + offset] += 1;

        for(int i = 1; i < n; i++) {
            for(int s = -sum; s <= sum; s++) {
                if(dp[i-1][s + offset] != 0){
                    dp[i][s + nums[i] + offset] += dp[i-1][s + offset];
                    dp[i][s - nums[i] + offset] += dp[i-1][s + offset];

                }
            }
        }
        return dp[n-1][target + offset];
    }
};