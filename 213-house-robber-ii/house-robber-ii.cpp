class Solution {
    private:
    int helper(vector<int>& arr,int idx,vector<int>& dp,int start){
        if(idx < start)return 0;
        
        if(dp[idx] != -1)return dp[idx];

        int pic = arr[idx] + helper(arr,idx - 2,dp,start);
        int nonpic = helper(arr,idx - 1,dp,start);

        return dp[idx] = max(pic,nonpic);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];

        vector<int>dp(n,-1);
        vector<int>dp1(n,-1);

        int ans1 =  helper(nums,n-2,dp,0);
        int ans2 =  helper(nums,n-1,dp1,1);

        return max(ans1,ans2);
    }
};