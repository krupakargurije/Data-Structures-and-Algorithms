class Solution {
    private:
    bool helper(vector<int>& nums,int target,int idx,int curr,vector<vector<int>> &dp){
        if(curr == target)return true;
        if(idx < 0 || curr > target)return false;
        if(dp[idx][curr] != -1)return dp[idx][curr];

        bool nonPic = helper(nums,target,idx - 1,curr,dp);
        
        bool pic = false;
        if(curr + nums[idx] <= target)
            pic = helper(nums,target,idx - 1,curr + nums[idx],dp);

        return dp[idx][curr] = pic || nonPic;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i : nums)totalSum += i;
        int tar = totalSum /2;
        if(totalSum % 2 != 0)return false;
        vector<vector<int>> dp(n ,vector<int>(tar + 1 , -1));

        return helper(nums,tar,n - 1,0,dp);
    }
};