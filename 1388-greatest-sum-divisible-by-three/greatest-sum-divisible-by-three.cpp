class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(3, INT_MIN);
        dp[0] = 0;
        
        for(int x : nums){
            vector<int> cur = dp;
            for(int r = 0; r < 3; r++){
                int nr = (r + x) % 3;
                cur[nr] = max(cur[nr], dp[r] + x);
            }
            dp = cur;
        }
        
        return dp[0];
    }
};