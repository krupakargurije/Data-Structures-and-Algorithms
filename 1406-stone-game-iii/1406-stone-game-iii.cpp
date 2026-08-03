class Solution {
    // private:
    // int helper(vector<int> &nums , int idx , vector<int> &dp){
    //     int n = nums.size();
    //     if(idx >= n)
    //         return 0;

    //     if(dp[idx] != INT_MIN)
    //         return dp[idx];
        
    //     int one = INT_MIN , two = INT_MIN , three = INT_MIN;
    //     one = nums[idx] - helper(nums , idx + 1 , dp);
    //     if(idx + 1 < n)
    //         two = (nums[idx] + nums[idx + 1]) - helper(nums , idx + 2 , dp);
    //     if(idx + 2 < n)
    //         three = (nums[idx] + nums[idx + 1] + nums[idx + 2]) - helper(nums , idx + 3 , dp);
    //     return dp[idx] = max({one , two , three});
    // }
public:
    string stoneGameIII(vector<int>& nums){
        int n = nums.size();
        vector<int>dp(n + 1, INT_MIN);
        // int diff = helper(nums , 0 , dp);

        dp[n] = 0;
        for(int i = n - 1; i >= 0; i--){
            int taken = 0;
            for(int k = 0;k<3 && i + k < n;k++){
                taken += nums[i + k];

                dp[i] = max(dp[i] ,taken - dp[i + k + 1]);
            }
        }

        int diff = dp[0];
        if(diff > 0) 
            return"Alice";

        else if(diff < 0)
            return "Bob";
        return "Tie";
    }
};