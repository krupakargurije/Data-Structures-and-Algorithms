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
        if(nums.empty())return 0;
        int n = nums.size();

        if(n == 1)return nums[0];
        // vector<int>dp(n + 1 , 0);
        // return helper(n - 1 , nums , dp);

        int prev = nums[0];
        int curr = max(nums[1] , nums[0]);

        for(int i = 2;i<n;i++){
            int temp = max(prev + nums[i], curr);

            prev = curr;
            curr = temp;
        }
        return curr;
    }
};