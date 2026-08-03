class Solution {
    private:
    int helper(vector<int> &nums , int idx , vector<int> &dp){
        if(idx < 0)
            return 0;
        if(idx == 0)
            return nums[idx];
        
        if(dp[idx] != 1e5)
            return dp[idx];

        int one = nums[idx] + helper(nums , idx - 1 , dp);
        int two = nums[idx] + helper(nums , idx - 2 , dp);

        return dp[idx] = min(one , two);
    }
public:
    int minCostClimbingStairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , 1e5);

        return min(helper(nums , n - 1 , dp) , helper(nums , n - 2 , dp));
    }
};