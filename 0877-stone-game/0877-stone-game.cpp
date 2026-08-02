class Solution {
    private:
    int helper(int left , int right , vector<int> &nums , vector<vector<int>> &dp){
        if(left == right)
            return nums[left];

        if(dp[left][right] != -1)
            return dp[left][right];

        int leftPic = nums[left] - helper(left + 1 , right , nums , dp);
        int rightPic = nums[right] - helper(left , right - 1 , nums , dp);

        return dp[left][right] = max(leftPic , rightPic);
    }
public:
    bool stoneGame(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n , vector<int>(n , -1));
        return helper(0 , n - 1 ,nums , dp) > 0;
    }
};