class Solution {
private:
    int helper(vector<int>& nums, int idx, int sum, int target,
               vector<vector<int>>& dp, int offset) {

        if(idx == nums.size()){
            return sum == target;
        }

        if(dp[idx][sum + offset] != -1)
            return dp[idx][sum + offset];

        int add = helper(nums, idx + 1, sum + nums[idx], target, dp, offset);
        int subtract = helper(nums, idx + 1, sum - nums[idx], target, dp, offset);

        return dp[idx][sum + offset] = add + subtract;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = 0;
        for(int x : nums) sum += x;

        int offset = sum;
        vector<vector<int>> dp(nums.size(),
                               vector<int>(2 * sum + 1, -1));

        return helper(nums, 0, 0, target, dp, offset);
    }
};