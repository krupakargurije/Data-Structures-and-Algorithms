class Solution {
    private:
    int helper(int l , int r , int turn , vector<int>& nums ,  vector<vector<vector<int>>> &dp){
        if(l > r)
            return 0;

        if(dp[l][r][turn] != -1)return dp[l][r][turn];

        if(!turn){
            return dp[l][r][turn] = max(nums[l] + helper(l + 1 , r , 1 , nums , dp) , 
            nums[r] + helper(l , r - 1 , 1 , nums , dp));
        }
        return dp[l][r][turn] = min(helper(l + 1 , r , 0 , nums , dp) , helper(l , r - 1 , 0 , nums , dp));
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(21, vector<vector<int>>(21, vector<int>(2, -1)));

        int sum = 0;
        for(int i : nums){
            sum += i;
        }
        int curr =  helper(0 , n - 1 , 0 , nums , dp);
        return curr >= (sum - curr);
    }
};