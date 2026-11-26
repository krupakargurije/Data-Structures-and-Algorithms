class Solution {
    // private:
    // int helper(int idx , vector<int> &nums , vector<int> &dp){
    //     if(idx < 0)return 0;

    //     if(dp[idx] != -1)
    //         return dp[idx];

    //     int take = nums[idx] + helper(idx - 2 , nums , dp);
    //     int skip = helper(idx - 1 , nums , dp);

    //     return dp[idx] = max(take , skip);
    // }
public:
    int rob(vector<int>& nums){
        int n = nums.size();

        if(n == 1)return nums[0];
        vector<int>dp(n + 1 , 0);
        // return helper(n - 1 , nums , dp);

        dp[0] = nums[0];
        dp[1] = max(nums[1] , nums[0]);

        for(int i = 2;i<n;i++){
            int pic = nums[i] + dp[i - 2];
            int skip = dp[i - 1];

            dp[i] = max(pic , skip);
        }
        return dp[n - 1];
    }
};












