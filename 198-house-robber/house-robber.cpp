class Solution {
    private:
    int helper(vector<int>& nums,vector<int>& dp,int idx){
        if(idx == 0)return nums[0];
        if(idx < 0)return 0;

        if(dp[idx] != -1)return dp[idx];

        int pic = nums[idx] + helper(nums,dp,idx-2);
        int nonpic = 0 + helper(nums,dp,idx-1);

        return dp[idx] = max(pic,nonpic);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return helper(nums,dp,n-1);
    }
};