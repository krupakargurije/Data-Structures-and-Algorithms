class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int mx = nums.back();
        vector<int> dp(mx + 2, 0);
        int ans = 1;

        for (int x : nums) {
            dp[x + 1] = dp[x] + 1;
            dp[x] = dp[x - 1] + 1;
            ans = max(ans, max(dp[x], dp[x + 1]));
        }
        return ans;
    }
};