class Solution {
    vector<int>dp;
    int helper(int idx , vector<int> &nums){
        if(idx < 0)return 0;

        if(dp[idx] != -1)return dp[idx];
        
        int rob = nums[idx] + helper(idx - 2 , nums);
        int skip = helper(idx - 1 , nums);

        return dp[idx] = max(rob , skip);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n + 1 , -1);
        return helper(n - 1 , nums);
    }
};