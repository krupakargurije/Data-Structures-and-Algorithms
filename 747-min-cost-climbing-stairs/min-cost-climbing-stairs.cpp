class Solution {
    // private:
    // int helper(vector<int> &nums , int idx , vector<int> &dp){
    //     if(idx < 0)
    //         return 0;
    //     if(idx == 0)
    //         return nums[idx];
        
    //     if(dp[idx] != 1e5)
    //         return dp[idx];

    //     int one = nums[idx] + helper(nums , idx - 1 , dp);
    //     int two = nums[idx] + helper(nums , idx - 2 , dp);

    //     return dp[idx] = min(one , two);
    // }
public:
    int minCostClimbingStairs(vector<int>& nums) {
        int n = nums.size();

        int curr = 0 , prev = 0;

        for(int i = 2;i<=n;i++){
            int temp = min(curr + nums[i-1] , prev + nums[i - 2]);
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};