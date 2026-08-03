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
    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int one = nums[i] - dp[i + 1];

            int two = INT_MIN;
            if (i + 1 < n)
                two = nums[i] + nums[i + 1] - dp[i + 2];

            int three = INT_MIN;
            if (i + 2 < n)
                three = nums[i] + nums[i + 1] + nums[i + 2] - dp[i + 3];

            dp[i] = max({one, two, three});
        }

        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};