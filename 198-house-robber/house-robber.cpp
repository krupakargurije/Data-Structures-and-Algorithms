class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        int prev1 = max(nums[0],nums[1]);
        int prev2 = nums[0];
        
        for(int i = 2;i<n;i++){
            int pic = nums[i] + prev2;
            int nonpic = prev1;

            int curr = max(pic,nonpic);

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};