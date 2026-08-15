class Solution {
    vector<int>dp;
    // int helper(int idx , vector<int> &nums){
    //     if(idx < 0)return 0;

    //     if(dp[idx] != -1)return dp[idx];

    //     int rob = nums[idx] + helper(idx - 2 , nums);
    //     int skip = helper(idx - 1 , nums);

    //     return dp[idx] = max(rob , skip);
    // }
public:
    int rob(vector<int>& nums){
        int n = nums.size();

        if(n == 1)return nums[0];

        // dp.assign(n + 1 , 0);

        // dp[0] = nums[0];
        // dp[1] = max(nums[0] , nums[1]);

        int prev = nums[0];
        int curr = max(nums[0] , nums[1]);

        for(int i = 2;i<n;i++){
            int rob = nums[i] + prev;
            int skip = curr;

            int temp = max(rob , skip);

            prev = curr;
            curr = temp;
            
        }
        return curr;
    }
};