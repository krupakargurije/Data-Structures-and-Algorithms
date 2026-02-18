class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i : nums)totalSum += i;

        int tar = totalSum /2;
        if(totalSum % 2 != 0)return false;

        vector<vector<bool>> dp(n ,vector<bool>(tar + 1 , 0));

        for(int i = 0;i< n;i++)dp[i][0] = true;

        if(nums[0] <= tar)
            dp[0][nums[0]] = true;

        for(int idx = 1;idx<n;idx++){
            for(int target = 1;target <= tar;target++){
                bool nonPic = dp[idx - 1][target];

                bool pic = false;
                if(nums[idx] <= target)
                    pic = dp[idx - 1][target - nums[idx]];
                    
                dp[idx][target] = pic || nonPic;
            }
        }
        return dp[n-1][tar];
    }
};










