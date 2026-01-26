class Solution {
    private:
    int helper(vector<int>& nums,vector<int>& dp,int idx){
        if(dp[idx] != -1)return dp[idx];
        int best = 1;
        
        for(int j = idx - 1;j >= 0;j--){
            if(nums[j] < nums[idx]){
                best = max(best,1 + helper(nums,dp,j));
            }
        }
        return dp[idx] = best;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);

        int ans = 0;
        for(int i = n-1;i >= 0;i--){
            int temp = helper(nums,dp,i);
            ans = max(ans,temp);
        }
        return ans;
    }
};